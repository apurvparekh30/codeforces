#include <bits/stdc++.h>

using namespace std;

string rec_min(bool first,int m, int n) {
  if(m == 0 && n == 0)  {
    return ""; 
  }
  string res = "";
  for(int i=0;i<=9;i++) {
    if(first && i == 0) continue;
    if((n - i) > ((m - 1) * 9)) continue;
    res += to_string(i) + rec_min(false, m - 1, n - i);
    break;
  } 
  return res;
}

string rec_max(int m,int n) {
  if(m == 0 && n == 0) {
    return "";
  }
  string res = "";
  for(int i=9;i>=0;i--) {
    if((n-i) < 0) {
      continue;
    }
    res += to_string(i) + rec_max(m-1,n-i);
    break;
  }
  return res;
}

int main() {
  int n,m;
  cin >> m >> n; 
  if(n == 0) {
    if(m == 1) {
      cout << "0 0"<< "\n";
    } else {
      cout << "-1 -1" << "\n";
    }
    return 0;
  }
  if(m * 9 < n) {
    cout << "-1 -1\n";
    return 0;
  }
  cout << rec_min(true, m, n) << " " << rec_max(m,n) << "\n";
  return 0;
}
