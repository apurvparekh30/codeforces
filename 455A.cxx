#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  const int MAX = 1e5 + 1;
  long long cnt[MAX];
  long long dp[MAX];
  fill(cnt , cnt + MAX ,0);
  fill(dp, dp + MAX,0);
  for(int i=0;i<n;i++) {
    int no;
    cin>>no;
    cnt[no]++;
  }
  dp[1] = cnt[1];
  for(int i=2;i<MAX;i++) {
    dp[i] = max(dp[i-1],dp[i-2] + cnt[i] * i);
  }
  cout << dp[MAX-1] << endl;
  
  return 0;
}

