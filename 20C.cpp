#include <bits/stdc++.h>
using namespace std;

const int maxx = 100001;
const long long oo = 999999999999;
vector<pair<long long ,int>> adj[maxx];
long long dist[maxx];
int parent[maxx];
int n,m;
int main() {
  cin>>n>>m;
  n = n + 1;
  fill(dist,dist+n,oo);
  fill(parent,parent + n,-1);
  while(m--) {
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back(make_pair(w,v));
    adj[v].push_back(make_pair(w,u));
  }
  priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
  pq.push(make_pair(0,1));
  dist[1] = 0;
  long long ans = oo;
  while(!pq.empty()) {
    pair<int,int> curr = pq.top();
    pq.pop();
    if(dist[curr.second] < curr.first)
      continue;
    if(curr.second == n-1) {
      //cout << curr.first;
      ans = curr.first;
      break;
    }
    for(pair<long long ,int>& pp: adj[curr.second]) {
      if(dist[curr.second] + pp.first < dist[pp.second]) {
        dist[pp.second] = dist[curr.second] + pp.first;
        parent[pp.second] = curr.second;
        pq.push(make_pair(dist[pp.second],pp.second));
      }
    }
  }
  if(ans == oo) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> path;
  for(int v = n-1; v!= -1;v = parent[v]) {
    path.push_back(v);
  }
  for(int i=path.size()-1;i>0;i--) {
    cout << path[i] << " ";
  }
  cout << path[0] <<endl;
  return 0;
}
