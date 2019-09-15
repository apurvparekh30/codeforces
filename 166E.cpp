/*
 * Observations
 * You have four vertices. All Vertices are connected to each other.
 * One can solve this with dp. Dp state would be number of steps remaining and last seen character.
 * Now for transition there will be a trick. You can't have your n-1th step to D. because in every step one can only move to other vertices.
 * The problem with this approach is your n can be 10e7 and you have 4 options as last vertices. so your total number of states are 10e7 * 4.
 * This will definitely cause in memory problem.
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000001;
const int MOD = 1000000007;


// Memory limit exceeded approach
/*
int dp[4][MAX];

int rec(int last,int n) {
  if(last == 3 && n == 1)
    return 0;
  if(n == 1) 
    return 1;
  int& ret = dp[last][n];
  if(ret!=-1) return ret;
  ret = 0;
  for(int i=0;i<=3;i++) {
    if(i == last) continue;
    ret = (ret + rec(i,n-1)) % MOD;
  }
  return ret % MOD;
}
*/
int main() {
  int n;
  cin>>n;
  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if(n==2){
    cout << 3 << endl;
    return 0;
  }
  long long ans = 1;
  while(n > 2) {
    ans = (ans * 3) % MOD;
    n--;
  }
  long long  to_add = ans / 3;
  ans = (ans * 2) % MOD;
  ans = (ans + to_add) % MOD;
  cout << ans << endl;
  return 0;
}

