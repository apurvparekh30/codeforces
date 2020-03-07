#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> b_mp;
int n;
int smaller[1000000 + 1];
int dp[1000000 + 1];

int rec(int i) {
  if(i < 0) {
    return 0;
  }
  if(dp[i] != -1) return dp[i];
  dp[i] = 0;
  if(i - b_mp[i] < 0) {
    dp[i] = 1;
    return dp[i];
  }
  dp[i] = max(dp[i],1 + rec(smaller[i - b_mp[i]]));
  return dp[i];
}

int main() {
  cin >> n;
  int a, b;
  int max_a = 0;
  for(int i=0;i<n;i++) {
    cin >> a >> b;
    max_a = max(max_a,a);
    b_mp.emplace(make_pair(a,b));
  }
  int low = -1;
  for(int i=0;i<=max_a;i++) {
    smaller[i] = low;
    if(b_mp.find(i) != b_mp.end()) {
      low = i;
    }
  }
  fill(dp, dp+1000000+1, -1);
  int ans = 0;
  for(auto& p:b_mp) {
    ans = max(ans, rec(p.first));
  }
  cout << b_mp.size() - ans << "\n";
  return 0;
}
