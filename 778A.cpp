#include <bits/stdc++.h>

using namespace std;

int arr[200001];
string t,p;

bool possible(int n) {
  string t_ = t;
  for(int i=0;i<n;i++)
    t_[arr[i]] = '-';
  int i = 0; int j = 0;
  while(i < p.length() &&  j < t_.length()) {
    if(t_[j] == p[i]){
      i++;
      j++;
      continue;
    }
    j++;
  }
  return (i == p.length());
}

int binary_search_(int low ,int high) {
  if(low >= high) {
    return low;
  }
  int mid = low + (high - low) / 2;
  if(possible(mid+1)) {
    return binary_search_(mid+1,high); 
  } 
  return binary_search_(low,mid);
}

int main() {
  cin >> t >> p;
  int n = t.length();
  for(int i=0;i<n;i++) {
    cin >> arr[i];
    arr[i]--;
  }
  int low = 0;
  int high = t.length()-1;
  int ans = binary_search_(low, high);
  cout << ans << "\n";
  return 0;
}
