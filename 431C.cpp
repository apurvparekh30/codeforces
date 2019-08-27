#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int n,k,d;
int dp[101][101][2];
const int MOD = 1000000007;

int rec(int i,int w,int hasD) {
  if(w == n) {
    return (hasD == 1) ? 1 : 0;
  }
  int& ret = dp[i][w][hasD];
  if(ret!=-1) return ret;
  ret = 0;
  for(int ww=1;ww<=k;ww++) {
    if(w + ww <= n) {
      ret = (ret + (rec(i+1,w+ww,(hasD == 1) ? 1 : ((ww >= d) ? 1 : 0)) % MOD))%MOD;
    }
  }
  return ret;
}

int main() {
  scanf("%d %d %d",&n,&k,&d);
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=n;j++) {
      fill(dp[i][j],dp[i][j]+2,-1);
    }
  }
  printf("%d\n", rec(0,0,0));
}
