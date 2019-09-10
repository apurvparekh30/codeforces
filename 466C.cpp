/*
 * Observation
 * List we need to divide into 3 parts. 
 * That means sum of all the elements should be divisible by 3.
 * We can deduce the what will be the sum of each part from this. target = (sum of all the elements) / 3.
 * We can use dp to count number ways to make a partition such that every partition is target size. 
 * To divide the list into 3 parts we need to make 2 buts in list. so dp state is going to be [index,remaining cuts]
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MAX = 5 * 100001;
ll a[MAX];
ll dp[MAX][3];
int n;
ll target;

ll rec(int i,int k,ll curr_sum) {
  if(k==0 && i==n) {
    return 1;
  }
  if(k == 0 || i == n)
    return 0;
  ll &ret = dp[i][k];
  if(ret != -1) {
    return ret;
  }
  ret = 0;
  ret += rec(i+1,k,curr_sum + a[i]);
  if(curr_sum + a[i] == target) {
    ret += rec(i+1,k-1,0);
  }
  return ret;
}

int main() {
  cin>>n;
  for(int i=0;i<n;i++) {
    fill(dp[i],dp[i]+3,-1);
  }
  ll sum = 0;
  for(int i=0;i<n;i++) {
    cin>>a[i];
    sum += a[i];
  }
  if(sum % 3 != 0) {
      cout << 0 << endl;
      return 0;
  }
  else {
    target = sum / 3;
  }
  ll ret = rec(0,3,0);
  cout<<ret<<endl;
}
