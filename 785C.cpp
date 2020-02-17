#include <bits/stdc++.h>

using namespace std;

int64_t n, m;

bool can_empty(int64_t day) {
  int64_t ret = day * (day+1) / 2;
  if(ret >= n) 
    return true;
  return false;
}

int64_t rec(int64_t low,int64_t high) {
  if(low >= high) return low;
  int64_t mid = low + (high - low) / 2; 
  if(can_empty(mid)) {
    return rec(low,mid);
  } 
  return rec(mid + 1, high);
}

int main() {
  cin >> n >> m;
  if(n <= m) {
    cout << n << "\n";
    return 0;
  }
  n = n - m;
  int64_t ans = rec(0, 2e9);
  cout << ans + m << "\n";
  return 0;
}
