#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n,m; cin >> n >> m;
    int l = m+n-1;
    vector<vector<int>> dp(l, vector<int>(2, 0));
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        int no; cin >> no;
        int d = i + j;
        //cout << d << '\n';
        dp[d][no]++;
      }
    }
    int ans = 0;
    for(int i=0,j=l-1;i < j;i++,j--) {
      int ones = dp[i][1] + dp[j][1];
      int zeros = dp[i][0] + dp[j][0];
      if(zeros < ones) {
        ans = ans + zeros; 
      } else {
        ans = ans + ones;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
