#include <bits/stdc++.h>
using namespace std;

int n,q;
int arr[2 * 100000 + 1];
int last1update[2 * 100000 + 1];
int st[4 * 2 * 100000 + 1];
int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
void updateTree(int p, int L, int R, int idx, int val) {
  if(idx < L || idx > R) return;
  if(L == idx && R == idx) {
    st[p] =  val;
  } else {
    updateTree(left(p), L, L + (R - L) / 2, idx, val);
    updateTree(right(p), (L + (R - L)/ 2) + 1, R, idx, val);
    int p1 = st[left(p)]; int p2 = st[right(p)];
    st[p] = max(p1,p2);
  }
}

int rmq(int p, int L, int R, int i, int j){
  if(i > R || j < L) return -1;
  if(L >= i && R <= j) return st[p];
  int p1 = rmq(left(p), L, L + (R - L) / 2, i , j);
  int p2 = rmq(right(p), (L + (R - L) / 2) + 1, R, i , j);
  return max(p1, p2);
}

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }
  cin >> q;
  fill(last1update, last1update + n, -1);
  for(int i=0;i<q;i++) {
    int type; cin >> type;
    if(type == 2) {
      int x; cin >> x;
      updateTree(1, 0, q - 1, i, x);
    } else {
      int p; cin >> p; p--;
      int x; cin >> x;
      arr[p] = x;
      last1update[p] = i;
    }
  }
  for(int i=0;i<n;i++) {
    int ans = max(arr[i], rmq(1,0,q-1,last1update[i]+1,q-1));
    cout << ans << " ";
  }
  cout << "\n";
}
