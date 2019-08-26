#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> adj[100005];
bool hasCat[100005];


int dfs(int u,int cats,int parent) {
  int ans = 0;
  bool flag = false;
  for(int v:adj[u]) {
    if(v == parent)
      continue;
    if(hasCat[v] && cats <= 0) {
      flag = true;
      continue;
    }
    flag = true;
    ans = ans + dfs(v,(hasCat[v] ? cats-1 : m),u);
  }
  if(!flag) 
    return 1;
  return ans;
}

int main() {
  cin >> n >> m;
  n++;
  fill(hasCat,hasCat+n,false);
  for(int i=1;i<n;i++) {
    int has;
    cin >> has;
    hasCat[i] = (has == 1) ? true : false;
  }
  for(int i=1;i<n-1;i++) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if(hasCat[1] && m == 0) {
    cout << 0 << endl;
  }
  else {
    int ret = dfs(1,(hasCat[1] ? m-1 : m),-1);
    cout << ret << endl;
  }
}
