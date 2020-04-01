#include <bits/stdc++.h>

using namespace std;

int n,m;
string str;

bool isAlpha(char c) { return c>='a' && c<='z';}

int main() {
  cin >> n >> m;
  cin >> str;
  int pairs = 0;
  for(int i=0;i<n;i++) {
    if(i == 0) {
      continue;
    }
    if(str[i] == '.' && str[i-1] == '.') {
      pairs++;
    }
  }
  while(m--) {
    int idx; char c;
    cin >> idx >> c;
    idx--;
    if(isAlpha(str[idx]) && isAlpha(c)) {
      cout << pairs << "\n";
      continue;
    } 
    if(!isAlpha(str[idx]) && !isAlpha(c)) {
      cout << pairs << "\n";
      continue;
    }
    if(isAlpha(c)) {
      if(idx > 0 && str[idx-1] == '.') pairs--;
      if(idx < n-1 && str[idx+1] == '.') pairs--;
    } else {
      if(idx > 0 && str[idx-1] == '.') pairs++;
      if(idx < n-1 && str[idx+1] == '.') pairs++;
    }
    cout << pairs << "\n";
    str[idx] = c;
  }
  return 0;
}

