#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k;
const int MAX = 501;
string grid[MAX];

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

const int oo = 987654321;
/*
bool dfs(int i,int j,int k,bool visited[MAX][MAX]) {
  grid[i][j] = 'X';
  visited[i][j] = true;
  if(k == 0){
    return true;
  }

  for(int idx=0;idx<4;idx++) {
    int ii = i + dr[idx];
    int jj = j + dc[idx];
    if(ii<0 || ii>=n || jj<0 || jj>=m || visited[ii][jj] || grid[ii][jj]!='.') {
      continue;
    }
    if(dfs(ii,jj,k-1,visited))
      return true;
  }
  grid[i][j] = '.';
  return false;
}*/

void dfs(int i,int j) {
  if(k==0)
    return;
  grid[i][j] = 'X';
  k--;
  for(int idx=0;idx<4;idx++) {
    int ii = i + dr[idx];
    int jj = j + dc[idx];
    if(ii<0 || ii>=n || jj<0 || jj>=m || grid[ii][jj]!='.')
      continue;
    dfs(ii,jj);
  }
}

void output() {
  for(int i=0;i<n;i++) {
    string& str = grid[i];
    for(char c:str) {
      if(c == '.')
        cout << 'X';
      else if(c == 'X')
        cout << '.';
      else 
        cout << c;
    }
    cout << endl;
  }
}

int main() {
  cin>>n>>m>>k;
  int cnt = 0;
  for(int i=0;i<n;i++) {
    cin >>grid[i];
    for(char c: grid[i]) {
      if(c == '.')
        cnt++;
    }
  }
  k = cnt - k;
  //bool visited[MAX][MAX];
  //for(int i=0;i<n;i++) fill(visited[i],visited[i] + m, false);
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(grid[i][j]=='.') {
        dfs(i,j);
      }
    }
  }
  output();
  return 0;
}

