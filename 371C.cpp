#include <bits/stdc++.h>
using namespace std;

string s;
int a,b,c;
int x,y,z;
long long r;
int bcount, scount, ccount;

bool possible(long long no) {
  long long cost = 0;
  cost += (max(no * bcount - a,0LL)) * x;
  cost += (max(no * scount - b,0LL)) * y;
  cost += (max(no * ccount - c,0LL)) * z;
  return cost <= r;
}
long long rec(long long low, long long high) {
  if(low == high) {
    return low;  
  }
  if(high == low + 1) {
    if(possible(high)) return high;
    return low;
  }
  long long mid = low + (high - low) / 2;
  if(possible(mid)) return rec(mid,high);
  return rec(low,mid-1);
}
int main() {
  cin >> s;
  cin >> a >> b >> c;
  cin >> x >> y >> z;
  cin >> r;

  for(char ch: s) {
    if(ch == 'B') bcount++;
    else if(ch == 'S') scount++;
    else if(ch == 'C') ccount++;
  }

  long long high = r + (a*x) + (b*y) + (c*z);

  cout << rec(0,high) << "\n";      
  return 0;
}
