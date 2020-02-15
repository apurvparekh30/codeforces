#include<bits/stdc++.h>

using namespace std;

int main() { 
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int n = s.length();
    int zero_count[n];
    zero_count[0] = s[0] == '1' ? 0 : 1;
    for(int i=1;i<n;i++) {
      if(s[i - 1] == '1') {
        if(s[i] == '1') zero_count[i] = 0;
        else zero_count[i] = 1;
      } else {
        if(s[i] == '1') zero_count[i] = zero_count[i-1]; 
        else zero_count[i] = zero_count[i-1] + 1;
      }
    }
    //for(int i=0;i<n;i++) cout << zero_count[i] << " " ;
    //cout << "\n";
    int cnt = 0;
    for(int i=0;i<n;i++) {
      if(s[i] == '0') 
        continue;
      cnt++;
      for(int no = 1,index = i + 1; no <= n && index < n ;index++) {
        if(s[index] == '0') no = no << 1;
        else no = (no << 1) + 1;
        int reduction = log2(no) + 1;
        int req_zeros = no - reduction;
        if(zero_count[i] >= req_zeros) cnt++;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
