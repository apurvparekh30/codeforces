#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
const int MAX = 100001;
ll dp[MAX][2];
ll cost[MAX];
string str[MAX];

int main() {
  cin>>n;
  for(int i=0;i<n;i++) {
    cin>>cost[i];
  }
  for(int i=0;i<n;i++) {
    cin>>str[i];
  }
  dp[0][1] = cost[0];
  for(int i=1;i<n;i++) {
    ll &ref = dp[i][0];
    ll &ref2 = dp[i][1];
    string copy = str[i-1];
    string copy1 = str[i];
    reverse(copy.begin(),copy.end());
    reverse(copy1.begin(),copy1.end());
    ref = LLONG_MAX;
    ref2 = LLONG_MAX;
    if(str[i-1] <= str[i]) {
      ref = dp[i-1][0];
    }
    if(copy <= str[i]) {
      ref = min(ref,dp[i-1][1]);
    }
    if(str[i-1] <= copy1 && dp[i-1][0]!=LLONG_MAX) {
      ref2 = cost[i] + dp[i-1][0];
    }
    if(copy <= copy1 && dp[i-1][1]!=LLONG_MAX) {
      ref2 = min(ref2,cost[i] + dp[i-1][1]);
    }
  }
  ll ans = min(dp[n-1][0],dp[n-1][1]);
  cout << ((ans == LLONG_MAX) ? -1 : ans) << endl;
  return 0;
}
