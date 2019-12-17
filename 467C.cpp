#include <bits/stdc++.h>

using namespace std;

int n,m,k;

long long arr[5001];
long long dp[5001][5001];

long long rec(int i,int k) {
  if(k == 0) return 0;
  long long& dummy = dp[i][k];
  if(dummy != -1) return dummy;
  if(k * m >= (n-i+1)){
    dummy = arr[i] + rec(i+m,k-1); 
  } else {
    dummy = max(arr[i]+rec(i+m,k-1),rec(i+1,k));
  }
  return dummy; 
}

int main(){
  for(int i=0;i<5001;i++) fill(dp[i],dp[i]+5001,-1);
  cin >> n >> m >> k;
  for(int i=1;i<=n;i++) {
    cin >> arr[i];
  }
  for(int i=n-1;i>=1;i--){
    arr[i] = arr[i] + arr[i+1];
  }
  for(int i=1; i+m<=n; i++) {
    arr[i] = arr[i] - arr[i+m];
  }
//  for(int i=1;i<=n;i++) cout << arr[i] << " "; cout << "\n";
  cout << rec(0,k) << "\n";
  return 0;
}
