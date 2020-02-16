#include <bits/stdc++.h>

using namespace std;

int n,k;

bool possible(int no) {
  int sum = no;
  if(sum >= n) return true;
  int divisor = 1;
  while(true) {
    long long tmp = (long long)divisor * k;
    if(tmp > 1000000000) break;
    divisor = divisor * k;
    if(divisor > no) break;
    sum = sum + (no / divisor); 
    if(sum >= n ) return true;
  }
  return false;
}

int rec(int low,int high) {
  if(low >= high) {
    return low;
  }
  int mid = low + (high - low) / 2;
  if(possible(mid)) {
    return rec(low,mid);
  }
  return rec(mid+1, high);    
}

int main() {
  cin >> n >> k;
  int low = 0;
  int high = n;
  int ans = rec(low,high);
  cout << ans << "\n";
  return 0;
}
