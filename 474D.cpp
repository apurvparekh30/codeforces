#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAX = 100001;
const int MOD = 1000000007;

ll dp[MAX];
ll sum[MAX];
int main() {
  int t,k;
  cin>>t>>k;
  fill(dp,dp+MAX,0);
  for(int i=0;i<MAX;i++) {
    dp[i] = (i - k < 0) ? 1 : dp[i-1] + dp[i-k];
    dp[i]%=MOD;
  }

  dp[0] = 0;
  for(int i=2;i<MAX;i++) dp[i] = (dp[i-1] + dp[i]) % MOD;
  while(t--) {
    int a,b;
    cin>>a>>b;
    cout << (dp[b] - dp[a-1] + MOD) % MOD << endl;   // in case of negative number adding mod
  }
  return 0;
}
