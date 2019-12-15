#include <bits/stdc++.h>

using namespace std;

int n,m;
string graph[51];
bool done[51][51];

int dr[4] = {1,0,-1,0};
int dc[4] = {0,-1,0,1};

bool rec(int i,int j,int pi, int pj) {
  for(int k = 0; k < 4; k++) {
    int ii = i + dr[k];
    int jj = j + dc[k];
    if(ii < 0 || ii >= n || jj < 0 || jj >= m) 
      continue;
    if(ii == pi && jj == pj)
      continue;
    if(graph[ii][jj] != graph[pi][pj])
      continue;
    if(done[ii][jj])
      return true;
    done[ii][jj] = true;
    if(rec(ii,jj,i,j))
      return true;
    done[ii][jj] = false;
  }   
  return false;
}

int main() {
  cin >>n>>m;
  for(int i=0;i<n;i++)
    cin>>graph[i];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(!done[i][j]) {
        if(rec(i,j,i,j)){
          cout <<"Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
