#include <iostream>
#include <string>

using namespace std;

bool have(string s) {
  bool ab = false;
  bool ba = false;

  for(int i=0;i<s.length()-1;) {
    if(!ab && s[i]=='A' && s[i+1]=='B'){
      if(ba) return true;
      ab = true;
      i = i + 2;
      continue;
    }
    if(!ba && s[i]=='B' && s[i+1]=='A') {
      if(ab) return true;
      ba = true;
      i = i + 2;
      continue;
    }
    i = i + 1;
  }
  return false;
}


int main() {
  string s;
  cin >> s;
  if(have(s))
    cout <<"YES"<<endl;
  else
    cout <<"NO"<<endl;
}
