#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2 * 100000 + 1];

bool mycompare(int a, int b) {
  if(a < 0) a = a * -1;
  if(b < 0) b = b * -1;
  return a < b;
}

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }

  sort(arr, arr+n,mycompare);
  
  int ans = 0;


  return 0;
}
