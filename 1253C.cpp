#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int64_t arr[n];
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n, greater<int64_t>());
  int64_t right[n];
  int64_t sum = 0;
  for(int i=n-1; i>=0; i--) {
    right[i] = arr[i];
    if((i + m) < n){
      right[i] += right[i+m];
    }
    int d = (i / m) + 1;
    sum += (d * arr[i]);
  }

  //cout << right[0] << '\n';

  int64_t ans[n+1];

  for(int i=0;i<n;i++) {
    ans[n-i] = sum;
    sum = sum - right[i];
  }

  for(int i=1;i<=n;i++) {
    cout << ans[i] << ' '; 
  }
  cout << '\n';
  return 0;
}
