#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
  cin >> t;
  while(t--) {
    int n,x; cin >> n >> x;
    int efficient, high_blow;
    for(int i=0;i<n;i++) {
      int u,v; cin >> u >> v;
      //cout << u  << " " << v << "\n";
      if(i == 0)  {
        efficient = u - v;
        high_blow = u;
        continue;
      }
      if((u - v) > efficient){
        efficient = u - v;
      }
      if(u > high_blow) {
        high_blow = u;
      }
    }

    int ans = 1;
    x = x - high_blow;

    if(x > 0) {
      if(efficient <= 0) ans = -1;
      else ans += (x + efficient - 1) / efficient;
    }
    cout << ans << "\n";
  }
  return 0;
}
