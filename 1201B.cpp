#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];

long int sum = 0;


int main() {
  cin>>n;
  for(int i=0;i<n;i++) {
    cin>>arr[i]; 
  }

  sort(arr, arr+n);

  for(int i=n-1;i>=0;i--) {
    if(sum <= 0) {
      sum = sum + arr[i];
    } else {
      sum = sum - arr[i];
    }
  }


  string yes = (sum == 0 ? "YES" : "NO");

  cout << yes << "\n";

  return 0;
}
