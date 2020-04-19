#include <bits/stdc++.h>

using namespace std;

int n,L;
int64_t cost[31];
int64_t right_[31];

int64_t rec(int L) {
  //cout << L << "\n";
  if(L <= 0) return 0;
  int idx = static_cast<int>(log2(L));
  //cout << idx << "\n";
  int64_t ans = 0;
  if(idx > n-1) {
    int q = L / (1 << (n-1));
    ans = (q * cost[n-1]) + rec(L - (q * (1 << (n-1))));
  }
  else if(idx == right_[idx]){
    ans = cost[idx] + rec(L - (1<<idx));
  } else {
    ans = cost[right_[idx]];
    ans = min(ans, cost[idx] + rec(L - (1<<idx)));
  }
  return ans;
}

int main() {
  cin >> n >> L;
  for(int i=0;i<n;i++) {
    cin >> cost[i];
    if(i > 0 && (cost[i-1]*2) < cost[i]) {
      cost[i] = cost[i-1] * 2;
    }
  }
  right_[n-1] = n-1;
  for(int i=n-2;i>=0;i--) {
    if(cost[right_[i+1]] < cost[i+1])  
      right_[i] = right_[i+1];
    else
      right_[i] = i+1;
  }
  int64_t ans = rec(L);
  cout << ans << "\n";
}
