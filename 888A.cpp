#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
      cin >> arr[i]; 
  }
  int ex_count = 0;
  for(int i=1;i<n-1;i++) {
    if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) ex_count++;
    if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) ex_count++;
  }
  cout << ex_count << "\n";
  return 0;
}
