#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100];

int dp[100][3];

const int oo = 987654321;

int rec(int i, int val) {
  if(i >= n) {
    return 0;
  }
  int& ref =  dp[i][val];
  if(ref != -1) return ref;
  ref = oo;
  if(arr[i] == 0) {
    ref = min(ref,1 + rec(i+1,0));
  } else if(arr[i] == 1 && val == 1) {
    ref = min(ref,1 + rec(i+1,0));
  } else if(arr[i] == 1 && val != 1){
    int temp = min(1 + rec(i+1,0),rec(i+1,1));
    ref = min(ref,temp);
  } else if(arr[i] == 2 && val == 2) {
    ref = min(ref,1 + rec(i+1,0));
  } else if(arr[i] == 2 && val != 2) {
    int temp = min(1 + rec(i+1,0),rec(i+1,2));
    ref = min(ref,temp);
  } else if(arr[i] == 3 && val == 0) {
    int temp = min(rec(i+1,1),rec(i+1,2));
    temp = min(temp,1+ rec(i+1,0));
    ref = min(ref,temp);
  } else if(arr[i] == 3 && val == 1) {
    int temp = min(1 + rec(i+1,0),rec(i+1,2));
    ref = min(ref,temp);
  } else if(arr[i] == 3 && val == 2) {
    int temp = min(1 + rec(i+1,0),rec(i+1,1));
    ref = min(ref,temp);
  }
  return ref;
}

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++) {
      dp[i][j] = -1;
    }
  }
  int ans = rec(0,0);
  cout << ans << "\n";
  return 0;
}
