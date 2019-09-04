#include <bits/stdc++.h>

using namespace std;

int g(int i,int n) {
  int size = 1<<(n+1);
  int ele = 1<<n;
  return size - ele + i;
}

int main() {
  int n,m;
  cin >> n >> m;
  int size = 1<<(n+1);
  vector<int> tree(size);
  for(int i=0;i<(1<<n);i++) {
    int ii = g(i,n);
    cin>>tree[ii];
  }
  for(int i=0;i<(1<<n);i++) {
    int level = 0;
    int ii = g(i,n);
     while(ii >= 1) {
      int& ref = tree[ii/2];
      if(level % 2 == 0) {
        ref = (ii%2==0) ? tree[ii] | tree[ii+1] : tree[ii] | tree[ii-1];
      }
      else {
        ref = (ii%2==0) ? tree[ii] ^ tree[ii+1] : tree[ii] ^ tree[ii-1];
      }
      ii = ii / 2;
      level++;
    }
  }
  while(m--) {
    int p,b;
    cin>>p>>b;
    int ii = g(p-1,n);
    //cout << ii << endl;
    tree[ii] = b;
    int level = 0;
    while(ii >= 1) {
      int& ref = tree[ii/2];
      if(level % 2 == 0) {
        ref = (ii%2==0) ? tree[ii] | tree[ii+1] : tree[ii] | tree[ii-1];
      }
      else {
        ref = (ii%2==0) ? tree[ii] ^ tree[ii+1] : tree[ii] ^ tree[ii-1];
      }
      ii = ii / 2;
      level++;
    }
    cout << tree[1] << endl;
  }
}
  


