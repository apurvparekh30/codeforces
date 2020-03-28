#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  int cost[1001];
  int total = 0;
  for(int i=1;i<=n;i++) {
    cin >> cost[i];
  }
  while(m--)  {
    int u,v; cin >> u >> v;
    int curr_cost = min(cost[u], cost[v]);
    total += curr_cost;
  }
  cout << total << "\n";
}

