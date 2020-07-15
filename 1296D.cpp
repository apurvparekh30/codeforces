#include <bits/stdc++.h>

using namespace std;

int n,a,b,k;

int main() {
  cin >> n >> a >> b >> k;
  int t = a + b;
  vector<int> v;
  int points = 0;
  for(int i=0;i<n;i++) {
    int hp; cin >> hp;
    int rem = hp % t;
    if(rem == 0) {
      v.push_back((b + (a-1))/a);
      continue;
    }
    if(rem > a) {
      rem = rem - a;
      v.push_back((rem + (a-1))/a);
      continue;
    }
    points++;
  }
  sort(v.begin(), v.end());
  for(auto& e: v) {
    if(e <= k) {
      points++;
      k = k - e;
    }
    if(k <= 0) break;
  }
  cout << points << '\n';
  return 0;
}
