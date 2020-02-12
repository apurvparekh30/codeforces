#include <bits/stdc++.h>

using namespace std;

int n;

int arr[100000 + 2];

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int sum = 0;
  int cnt = 0;
  for(int i = 0;i < n; i++) {
    if(arr[i] >= sum) {
      sum = sum + arr[i];
      cnt++;
    }
  }
  cout << cnt << "\n";
}
