#include <bits/stdc++.h>
int main() {
  int n, k;
  long long int arr[100001];
  std::cin >> n >> k;
  for(int i=0;i<n;i++)  std::cin >> arr[i];
  std::sort(arr, arr+n);
  std::unordered_set<long long int> ignore;
  int count = 0;
  for(int i=0;i<n;i++) {
    if(ignore.find(arr[i]) != ignore.end())  continue;
    count++;
    ignore.insert(arr[i] * k);
  }
  std::cout << count << "\n";
}
