#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  while(n--) {
    string curr;
    cin >> curr;
    if(curr.length() > 10) {
      string temp;
      temp = temp + curr[0];
      temp = temp + to_string(curr.length()-2);
      temp = temp + curr[curr.length()-1];
      cout << temp << endl;
    }
    else cout << curr << endl;
  }
    
  return 0;
}

