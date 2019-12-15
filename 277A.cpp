#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[101];
bool done[101];

void rec(int u) {
  if(adj[u].empty()) {
    done[u] = true;
    return;
  } 
  for(int v=1; v<=n; v++) {
    if(done[v]) continue;
    int i = 0, j = 0;
    vector<int>& a = adj[u];
    vector<int>& b = adj[v];
    bool common = false;
    while(i<a.size() && j<b.size()) {
      if(a[i] < b[j]) i++;
      else if(a[i] > b[j]) j++;
      else {
        common = true;
        break;
      }
    }
    if(common) {
      done[v] = true;
      rec(v);
    }
  }
}
int main() {
  cin >> n >> m;
  bool allzeros = true;
  for(int i=1;i<=n;i++){
    int cnt;
    cin >> cnt;
    while(cnt--){
      allzeros = false;
      int tmp;
      cin >> tmp;
      adj[i].push_back(tmp);
    }
    sort(adj[i].begin(),adj[i].end());
  }
  if(allzeros) {
    cout << n << "\n";
    return 0;
  }
  int ans = 0;
  for(int i=1;i<=n;i++) {
    if(!done[i]) {
      done[i] = true;
      ans++;
      rec(i);
    }
  }
  cout << ans-1 << "\n";
return 0;
}
