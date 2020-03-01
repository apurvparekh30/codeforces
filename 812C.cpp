#include <bits/stdc++.h>

using namespace std;

int n,s;

int possible(int k, vector<long long>& cost) {
  priority_queue<long long, vector<long long>, std::greater<long long>>  pq;
  for(int i=1; i<=n; i++) {
    long long to_add = static_cast<long long>(i) * static_cast<long long>(k);
    long long curr_cost = cost [i] + to_add;
    //cout << curr_cost << " ";
    pq.push(curr_cost);
  }
  //cout << "\n";
  long long total_cost = 0;
  for(int i=0;i<k;i++) {
    total_cost += pq.top();
    pq.pop();
  }
  //cout << k << " " << total_cost << "\n";
  if(total_cost > s) {
    return -1;
  }
  return total_cost;
}

pair<int,int> binarySearch(int low,int high, vector<long long>& cost) {
  if(low >= high) {
    int curr_cost = possible(low, cost);
    return make_pair(low, curr_cost);
  }
  int mid = low + (high - low) / 2;
  int curr_cost = possible(mid+1, cost);
  if(curr_cost != -1) {
      return binarySearch(mid+1,high,cost);
  }
  return binarySearch(low,mid,cost);
}

int main() {
  cin >> n >> s;

  vector<long long> cost(n+1);
  for(int i=1;i<=n;i++) {
    cin >> cost[i];
  }
  pair<int,int> ans = binarySearch(0,n,cost);
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}
