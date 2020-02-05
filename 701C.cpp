#include <bits/stdc++.h>

using namespace std;

int n;
string s;
const int oo = 987654321;
unordered_map<char ,int> char_count;
void mark_done(char c,long long& no) {
  int i = c - 'A';
  no = no | (1LL << i);
}
void mark_undone(char c,long long& no) {
  int i = c - 'A';
  no = no & ~(1LL << i);
}
int main() {
  cin >> n;
  cin >> s;

  long long have = 0, done = 0;
  for(char c:s) {
    mark_done(c,have);
  }
  int a = 0;
  int b = 0;
  int ans = oo;
  while(a < n) {
    while(done != have && b < n) {
      char c = s[b];
      char_count[c]++;
      mark_done(c,done);
      b++;
    }
    while(a < n && a < b) {
      if(done == have)
        ans = min(ans, b - a);   
      char c = s[a];
      char_count[c]--;
      if(char_count[c] == 0) {
        a++;
        mark_undone(c,done); 
        break;
      }
      a++;
    }
  }
  cout << ans << "\n";
  return 0;
}
