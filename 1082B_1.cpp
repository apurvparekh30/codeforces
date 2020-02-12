#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int right_g[2 * 100001];
int left_g[2 * 100001];
int res[2 * 100001];

int main() {
  cin >> n;
  cin >> s;
  s = s + "S";
  if(s[0] == 'G') {
    left_g[0] = 1;
  }
  for(int i = 1; i <= n; i++) {
    char c = s[i];
    if(c == 'S'){
      if(s[i-1] == 'G') {
        left_g[i] = left_g[i-1];
      } else {
        left_g[i] = 0;
      }
    }
    if(c == 'G'){
      
      if(s[i-1] == 'G') {
        left_g[i] = left_g[i - 1] + 1;
      } else {
        left_g[i] = 1;
      }
    }
  }
  for(int i = n-1; i >= 0; i--) {
    char c = s[i];
    if(c == 'S'){
      if(s[i+1] == 'G') {
        right_g[i] = right_g[i+1];
      } else {
        right_g[i] = 0; 
      } 
    }
    if(c == 'G' ){
      if(s[i+1] == 'G') {
        right_g[i] = right_g[i+1] + 1;
      } else {
        right_g[i] = 1;
      }
    }
  }
  for(int i=0;i<=n;i++) {
    int ans = 0;
    char c = s[i];
    if(c == 'S') {
      ans += left_g[i] + right_g[i];   
    } else {
      if(i > 0) {
        res[i] = res[i-1];
      }
    }
    if(i == 0) {
      res[i] = ans;
    } else {
      res[i] = max(res[i-1], ans);
      if(right_g[i] > 0 && res[i-1] + 1 > ans) {
        res[i] = res[i-1] + 1;
      }
    }
    cout << res[i] << "\n";
  }
  cout << res[n] << "\n";
  return 0;
}
