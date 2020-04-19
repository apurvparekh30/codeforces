#include <bits/stdc++.h>

using namespace std;

int n;
int64_t arr[2 * 100000 + 1];

bool good(int num,int64_t x) {
  int64_t tmp = x - arr[num];
  if(tmp < 0) tmp = tmp * -1;
  return (tmp <= x);
}

int binary_search_(int low, int high, int64_t x) {
  if(low == high) {
    return low;
  }
  int mid = low + (high - low) / 2;
  if(good(mid+1,x)) {
    return binary_search_(mid+1, high,x);
  }
  return binary_search_(low, mid,x);
}

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
    if(arr[i] < 0) arr[i] = arr[i] * -1;
  }
  sort(arr, arr+n);
  int64_t ans = 0;
  for(int i=0;i<n;i++) {
    int idx = binary_search_(i, n-1, arr[i]);
    //cout << idx << "\n";
    ans = ans + (idx-i);
  }
  cout << ans << "\n";
  return 0;
}
