#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int color[100001];
  unordered_map<int, vector<int>> graph;
  cin >> n;
  for(int i=0;i<n-1;i++) {
    int u,v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for(int i=1;i<=n;i++) {
    cin >> color[i];
  }
  int root = -1;
  pair<int,int> tmp = make_pair(-1,-1);
  for(int u=1;u<=n;u++) {
    int my_color = color[u];
    for(int& v:graph[u]) {
      if(v < u) continue;
      if(color[v] != my_color) {
        if(root == -1) {
          if(tmp.first == -1) {
            tmp = make_pair(u,v);
          } else {
            if(u == tmp.first || u == tmp.second) {
              root = u;
            } else if(v == tmp.first || v == tmp.second) {
              root = v;
            }
            else {
              //cout << u << " " << v << " " << tmp.first << " " << tmp.second << "\n";
              cout << "NO\n";
              return 0;
            }
          }
        } else {
          if(u != root && v != root) {
            cout << "NO\n";
            return 0;
          }
        }
      }
    }
  }
  if(root == -1 && tmp.first != -1) root = tmp.first;
  if(root == -1) root = 1;
  cout << "YES\n";
  cout << root << "\n";
  return 0;
}
