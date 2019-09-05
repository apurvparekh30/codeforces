#include <bits/stdc++.h>

using namespace std;

const int max = 2001;
const int mod = 1000000000 + 7;

long long dp[2001][2001];
int n,k;

int rec(int k,int n) {
  if(k == 0)
    return 1;
  long long& ret = dp[k][n];
  if(ret!=-1) return ret;
  ret = 0;
  for(int i=1;i * i<=n;i++) {
    if(n % i == 0) {
      ret = (ret + (rec(k-1,i) % mod))%mod;
      if(i  * i !=n)
        ret = ( ret + (rec(k-1,n/i)%mod))%mod;
    }
  }
  return ret%mod;
}


int main() {
  cin>>n>>k;
  for(int i=0;i<=k;i++) {
    fill(dp[i],dp[i]+n+1,-1);
  }
  long long ans = 0;
  for(int i=1;i<=n;i++) {
    int ret = rec(k-1,i);
    ans = (ans + ret) % mod;
  }
  cout << ans << endl;
  return 0;
}
