#include <bits/stdc++.h>

using namespace std;

int n;
string s;
bool left_g[100001];
bool right_g[100001];

int main() {
  cin >> n;
  cin >> s;
  left_g[0] = false;
  for(int i=1;i<s.length();i++) {
    left_g[i] = left_g[i-1] | (s[i-1] == 'G');
  }
  right_g[s.length()-1] = false;
  for(int i=s.length()-2;i>=0;i--) {
    right_g[i] = right_g[i+1] | (s[i+1] == 'G');
  }
  int a = 0;
  int b = 0;
  int ans = 0;
  int swaped_s = -1;
  bool swaped = false;
  while(b < s.length()) {
    if(s[b] == 'G') {
      ans = max(ans, b - a + 1);
      b++;
      continue;
    } 
    if(!swaped) {
      swaped = true;
      swaped_s = b;
      ans = max(ans, b - a + 1);
      b++;
      continue;
    }
    if(!right_g[b] && !left_g[a]) {
      ans = ans - 1;  
    }
    a = swaped_s + 1;
    if(swaped)
      swaped = false;
    else
      b++;
  }
  if(!right_g[b] && !left_g[a] && swaped) {
     ans = ans - 1;  
  }
  cout << max(0,ans) << "\n"; 
  return 0;
}
