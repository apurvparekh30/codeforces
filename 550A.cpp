#include <iostream>
#include <string>

using namespace std;

string s;
int dp[100001][2][2];

bool have(int i, int ab, int ba) {
  if(ab && ba)
    return 1;
  if(i >= s.length()-1)
    return 0;
  int& ret = dp[i][ab][ba];
  if(ret!=-1)
    return ret;
  ret = 0;
  if(s[i] == 'A' && s[i+1] =='B')
    ret += have(i+2,1,ba);
  if(s[i] == 'B' && s[i+1] =='A')
    ret += have(i+2,ab,1);
  ret+=have(i+1,ab,ba);
  return ret;
}


int main() {
  cin >> s;
  for(int i=0;i<s.length();i++) {
    for(int j=0;j<2;j++) {
      fill(dp[i][j],dp[i][j]+2,-1);
    }
  }
  if(have(0,0,0))
    cout <<"YES"<<endl;
  else
    cout <<"NO"<<endl;
}
