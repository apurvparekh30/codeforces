#include <bits/stdc++.h>

using namespace std;

int n,k;
int arr[2 * 100001];

bool can(int no) {
  int cnt = 0;
  for(int i=n/2; i < n && arr[i] < no; i++) {
    cnt = cnt + (no - arr[i]); 
    if(cnt > k)
      return false;
  }
  return true;
}

int rec(int low,int high) {
  if(low >= high) return low;
  int mid = low + (high - low) / 2;
  if(can(mid)) {
    if(can(mid+1)) {
      return rec(mid+1,high);
    }
    return mid;
  }
  return rec(low,mid-1);
}

int main() {
  cin >> n >> k;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr,arr+n);
  int ans = rec(arr[n/2],arr[n/2] + k);
  cout << ans << "\n";
  return 0;
}
