#include <bits/stdc++.h>

using namespace std;


int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    auto p = make_pair(0,0);
    map<pair<int,int>, int> dp = {
      {make_pair(0,0), -1}
    };
    int ans = -1;
    int l = 0, r = 0;
    for(int i=0;i<s.length();i++) {
      char c = s[i];
      if(c == 'D') p.first -= 1;
      if(c == 'U') p.first += 1;
      if(c == 'L') p.second -= 1;
      if(c == 'R') p.second += 1;
      auto iter = dp.find(p);
      if(iter != dp.end()) {
        //cout  << i << ' ' << p.first << ' ' << p.second << ' ' << iter->second << '\n';
        int tmp = (i - iter->second);
        if(ans == -1 || ans > tmp) {
          ans = tmp;
          l = iter->second + 1;
          r = i + 1;
        }
      } 
      dp[p] = i;
    }
    if(ans == -1) cout << "-1\n";
    else cout << l+1 << ' ' << r << '\n';
  }
  return 0;
}
