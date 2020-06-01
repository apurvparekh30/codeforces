#include <bits/stdc++.h>

using namespace std;

int main() {
  int q;
  cin >> q;
  while(q--) {
    int n, t;
    cin >> n >> t;
    vector<int64_t> arr, low,high;

    for(int i=0;i<n;i++) {
      int a; cin >> a;
      int l; cin >> l;
      int h; cin >> h;
      arr.push_back(a);
      low.push_back(l);
      high.push_back(h);
    }
    int64_t curr_low = t;
    int64_t curr_high = t;

    string ans = "YES";

    for(int i=0;i<n;i++) {
      int diff = arr[i] - (i == 0 ? 0 : arr[i-1]);

      int64_t next_high = min(curr_high + diff, high[i]);
      if(next_high < low[i]){
        ans = "NO"; 
        break;
      } 

      int64_t next_low = max(curr_low - diff, low[i]);
      if(next_low > high[i]) {
        ans = "NO";
        break;
      }

      curr_high = next_high;
      curr_low = next_low; 
    }
    cout << ans << "\n";
  }

  return 0;
}
