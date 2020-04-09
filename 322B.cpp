#include <bits/stdc++.h>

using namespace std;

int do_again(int a,int b, int c, int sub) {
  int ans = sub;
  if(a >= sub) a = a - sub; else return -1;
  if(b >= sub) b = b - sub; else return -1;
  if(c >= sub) c = c - sub; else return -1;

  ans = ans + (a/3);
  ans = ans + (b/3);
  ans = ans + (c/3);

  return ans;
}

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int ans = 0;

  ans = max(ans, do_again(a,b,c,1));
  ans = max(ans, do_again(a,b,c,2));
  ans = max(ans, do_again(a,b,c,0));

  cout << ans << "\n";

  return 0;
}
