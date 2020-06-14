#include <bits/stdc++.h>

using namespace std;

int arr[3];
int dp[5001];

const int oo = 987654321;

int rec(int n) {
  //cout << n << '\n';
  if(n % arr[0] == 0) return n/arr[0];
  if(n < arr[0]) return -oo;
  int& ref = dp[n];
  if(ref != -1) return ref;
  ref = -oo;
  for(int i=0;i<3;i++) {
    if(n - arr[i] >= 0) {
      ref = max(ref, 1 + rec(n - arr[i]));
    }
  }
  return ref;
}

int main() {
  int n; cin >> n;
  for(int i=0;i<3;i++) cin >> arr[i];
  sort(arr, arr+3);
  fill(dp, dp + n + 1, -1);
  cout << rec(n) << '\n';
  return 0;
}
