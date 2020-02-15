#include <bits/stdc++.h>

using namespace std;

int n;
int L;

long long int cost[30];

long long int rec(int ltr) {
  long long int min_cost = cost[0];
  int min_cost_index = 0;
  int min_multiplier = ltr;
  for(int i=1;i<n;i++) {
    if(min_cost > cost[i]) {
      min_cost = cost[i];
      min_cost_index = i;
      continue;
    }
    int q1 = ltr / (1 << min_cost_index);
    if(ltr % (1 << min_cost_index) != 0) {
      q1 = q1 + 1;
    }
    long long int cost1 = min_cost << q1;
    int q2 = ltr / (1 << i);
    if(ltr % (1<<i) != 0) {
      q2 = q2 + 1;
    }
    long long int cost2 = cost[i] << q2;
    if(cost1 > cost2) {
      min_cost = cost[i];
      min_cost_index = i;
      min_multiplier = q2;
    }
  }
  cout << min_cost << " " << min_cost_index << " " << min_multiplier << "\n";
  long long int ret = min_cost * min_multiplier; 
  return ret;
}

int main() {
  cin >> n >> L;
  for(int i=0;i<n;i++) {
    cin >> cost[i];
  }
  long long int ans = rec(L);
  cout << ans << "\n";
  return 0;
}
