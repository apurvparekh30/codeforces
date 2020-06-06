#include <bits/stdc++.h>

using namespace std;

int main() {
  int q; cin >> q;
  while(q--) {
    int n; cin >> n;
    int arr[n];
    int positives = 0;
    int first_positive = -1;
    int m = 0;
    int j = 0;
    for(int i=0;i<n;i++) {
      cin >> arr[j];
      if(arr[j] >= 0) {
        positives++;
        if(first_positive == -1) first_positive = arr[j];
      }
      if(j == 0) {
        j++; 
        continue;
      };
      if(arr[j-1] == -1 && arr[j] == -1) continue; // no need of continuous -1
      if(arr[j-1] != -1 && arr[j] != -1) {
        int diff = arr[j] - arr[j-1];
        if(diff < 0) diff = -diff;
        m = max(m, diff);
      }
      j++;
    }
    if(positives == 0) {
      cout << "0 0" << '\n'; 
      continue;
    }
    if(positives == 1) {
      cout << 0 << " " << first_positive << '\n';
      continue;
    }
    n = j;
    int _min = 1000000001;
    int _max = 0;
    for(int i=0;i<n;i++) {
      if(arr[i] == -1) {
        if(i-1 >= 0) {
          _min = min(_min, arr[i-1]);
          _max = max(_max, arr[i-1]);
        }
        if(i+1 < n) {
          _min = min(_min, arr[i+1]);
          _max = max(_max, arr[i+1]);
        }
      } 
    }
    int k = (_min + _max) / 2;
    m = max(m, max(k-_min, _max-k));
    cout << m << " " << k << '\n';
  }
  return 0;
}
