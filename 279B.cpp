#include <bits/stdc++.h>

using namespace std;

int n,t;
int arr[100001];
int sum[100001];

bool can(int start, int count) {
  if(start - count < 0) {
    return false; 
  }
  if(sum[start] - sum[start - count] > t) {
    return false;
  }
  return true;
}
int rec(int start,int low,int high) {
  if(low >= high) {
    return low;
  }
  int mid = low + (high - low) / 2;
  if(can(start,mid)) {
    if(can(start,mid+1)) {
      return rec(start,mid+1,high);
    } 
    return mid;
  } 
  return rec(start,low,mid-1);
 
}
int main() {
  cin>>n>>t;
  bool possible = false;
  for(int i=1;i<=n;i++) {
    cin>>arr[i];
    if(arr[i] <= t) possible = true;
    sum[i] = sum[i-1] + arr[i];
  }
  if(!possible) {
    cout << "0\n";
    return 0;
  }
  int ans = -1;
  for(int i=1;i<=n;i++) {
    ans = max(ans,rec(i,0,i));  
  }
  cout << max(ans,1) << "\n";
  return 0;
}
