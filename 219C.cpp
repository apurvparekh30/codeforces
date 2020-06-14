#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if(k == 2) {
    char curr = s[0]; 
    char next = (curr == 'A' ? 'B' : 'A');
    int ans1 = 0; int ans2 = 1; 
    for(int i=1;i<n;i++) {
      if(s[i] != next)  {
        ans1++;
      }
      if(s[i] != curr) {
        ans2++;
      }
      swap(curr, next);
    }
    if(ans1 > ans2) {
      ans1 = ans2;
      s[0] = (s[0] == 'A' ? 'B' : 'A');
    }
    for(int i=1;i<n;i++) s[i] = (s[i-1] == 'A' ? 'B' : 'A');
  
    cout << ans1 << '\n';
    cout << s << '\n';
    return 0;
  }

  int a = 0; int b = 1;
  int ans = 0; 
  while(b < n) {
    if(s[b] == s[a]) {
      b++;
      continue;
    }
    if(b - a > 1) {
      char r = 'A';
      if(s[a] == r) r++;
      if(b < n && s[b] == r) {
        r++; 
        if(s[a] == r) r++;    // s[a] might be greater than s[b]
      }
      //cout << r << ' ' << a << ' ' << b << '\n';
      for(int k = a + 1; k < b; k=k+2) {
        s[k] = r;
        ans++;
      }
    }
    a = b;
    b++;
  }
  if(b - a > 1) {
    char r = 'A';
    if(s[a] == r) r++;
    if(b < n && s[b] == r) {
      r++; 
      if(s[a] == r) r++;    // s[a] might be greater than s[b]
    }
    //cout << r << ' ' << a << ' ' << b << '\n';
    for(int k = a + 1; k < b; k=k+2) {
      s[k] = r;
      ans++;
    }
  }
  cout << ans << '\n' << s << '\n';

  return 0;
}
