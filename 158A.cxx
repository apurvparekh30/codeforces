#include <bits/stdc++.h>

using namespace std;

int findFirst(int low,int high,vector<int>& scores) {
  if(low > high)
    return -1;
  if(low == high) {
    return scores[low] == 0 ? low : -1;
  }
  int mid = low + (high - low) / 2;
  if(scores[mid] > 0)
    return findFirst(mid+1,high,scores);
  return findFirst(low,mid,scores);
}

int findLast(int low,int high,int target,vector<int>& scores) {
  if(low > high)
    return -1;
  if(low == high) 
    return scores[low] == target ? low : -1;
  int mid = low + (high - low)/2;
  if(scores[mid] < target) 
    return findLast(low,mid-1,target,scores);
  if(scores[mid+1] == target)
    return findLast(mid+1,high,target,scores);
  return mid;
}


int main() {
  int n,k;
  cin >> n >> k;
  vector<int> scores(n);
  for(int i = 0; i < n; i++) {
    cin>>scores[i];
  }
  int number = scores[k-1];
  if(number == 0) {
    int first = findFirst(0,k-1,scores);
    if(first == 0) 
      cout << 0 << endl;
    else
      cout << first << endl;
  }
  else {
    int last = findLast(k-1,n-1,number,scores);
    cout << last + 1 << endl;
  }
  return 0;
}
