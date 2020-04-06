#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;
  int left[1000001];
  int right[1000001];
  for(int i=s.length()-1;i>=0;i--) {
    if(s[i] == '1') right[i] = i;
    if(s[i] == '0' && i == s.length()-1) right[i] = s.length();
    if(s[i] == '0' && i < s.length()-1) right[i] = right[i+1]; 
  }
  long long int ans = 0;

  int l = 0; 
  int r = 0;
  int cnt = 0;
  if(k == 0) {
    while(l < s.length()){
      r = right[l];
      //cout << l << " " << r << "\n";
      long long int ll = static_cast<long long int>(r - l);
      ans = ans + (ll * (ll+1)/2);
      l = r + 1;
    }
    cout << ans << "\n";
    return 0;
  }

  while(r < s.length()) {
    if(s[r] == '1') {
      cnt++;
    } 
    if(cnt == k) {
      //cout << l << " " << r <<  " " << right[l] << "\n";
      long long int ll = static_cast<long long int>(right[l] - l + 1);
      ans = ans + ll;
    }
    if(cnt == k + 1){
      l = right[l] + 1;
      cnt = cnt - 1;
      long long int ll = static_cast<long long int>(right[l] - l + 1);
      ans = ans + ll;
    }
    r++;
  }
  cout << ans << "\n";
  return 0;
}
