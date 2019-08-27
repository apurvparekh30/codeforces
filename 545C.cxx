#include <iostream>
#include <stdio.h>
#include <algorithm>


using namespace std;

int n;
int dp[100001][3];
pair<int,int> a[100001];

int rec(int i,int t) {
  if(i == n)
    return 0;
  if(i == n-1)
    return 1;
  int& ref = dp[i][t];
  if(ref != -1)
    return ref;
  ref = 0;
  if(t==0 || t==1) {
    ref = max(ref,rec(i+1,0));
    
    if(a[i].first - a[i].second > a[i-1].first) {
      ref = max(ref,rec(i+1,1) + 1);
    }
    if(a[i].first + a[i].second < a[i+1].first) {
      ref = max(ref,rec(i+1,2) + 1);
    }
  }
  else {
    ref = max(ref,rec(i+1,0));
    if(a[i].first - a[i].second > a[i-1].first + a[i-1].second) {
      ref = max(ref,rec(i+1,1) + 1);
    }

    if(a[i].first + a[i].second < a[i+1].first) {
      ref = max(ref,rec(i+1,2) + 1);
    }
  }
  return ref;
}


int main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d %d",&a[i].first,&a[i].second);
  }
  for(int i=0;i<n;i++) {
    fill(dp[i],dp[i] + 3,-1);
  }
  printf("%d\n",rec(1,1) + 1);
  return 0;
}
