#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int binary_search_(int low ,int high, int num) {
  if(low >= high) {
    return low;
  } 
  int mid = low + (high - low) / 2;
  if(arr[mid + 1] <= (2 * num))  {
    return binary_search_(mid + 1, high, num);
  } 
  return binary_search_(low, mid, num);
}

int main() {
  int n; cin >> n;
  for(int i=0;i<n;i++) cin >> arr[i];
  sort(arr, arr+n);
  int ans = 987654321;
  for(int i=0;i<n-1;i++) {
    int right = binary_search_(i+1, n-1, arr[i]);
    //cout << i << ' ' << right << ' ' << arr[i] << ' ' << arr[right] << '\n';
    ans = min(ans, i + (n - right - 1));
  }
  cout << ans << '\n';
  return 0;
}
