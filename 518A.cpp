#include <bits/stdc++.h>

using namespace std;

string s,t;

int get_diff(char d, char c) {
  return (d - 'a') - (c - 'a');
}

string solve() {
  int n = s.length();
  int loc = -1;
  for(int i=n-1; i>=0; i--) {
    char c = s[i];
    char d = t[i];
    int diff = get_diff(d,c);
    if(diff <= 0) {
      continue; 
    }
    if((diff == 1 && loc!=-1) || diff > 1) {
      s[i]++;
      return s;
    } else {
      loc = i; 
    }
  }
  if(loc != -1 && loc != n-1) {
    for(int i=n-1;i>loc;i--) {
      if(s[i] == 'z') continue;
      s[i]++;
      return s;
    }
    s[loc]++;
    for(int i=loc+1;i<n;i++) {
      s[i] = 'a';
      if(s < t) return s;
    } 
  }
  return "No such string";
}

int main() {
  cin >> s >> t;
  string ans = solve();
  cout << ans << "\n";
  return 0;
}
