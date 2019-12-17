#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_map<string,int> u_map;
  int n; cin >> n;
  while(n--) {
    string s;
    cin >> s;
    if(u_map.find(s) == u_map.end()) {
      u_map[s] = 1;
      cout << "OK\n";
    } else {
      int curr = u_map[s];
      u_map[s]++;
      cout << s << curr << "\n";
    }
  }
  return 0;
}
