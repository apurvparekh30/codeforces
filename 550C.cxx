#include <iostream>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

string s;
int dp[101][1000];

int rec(int i,int num) {
  if(num % 8 == 0 && num!=0) {
    printf("YES\n%d\n",num);
    return 1;
  }
  if(i==s.length())
    return 0;
  if(dp[i][num]!=-1) 
    return dp[i][num];
  dp[i][num] = 0;
  dp[i][num] = rec(i+1,num);
  if(dp[i][num] == 0) {
    dp[i][num] = rec(i+1,((num * 10) + (s[i]-'0'))%1000);
  }
  return dp[i][num];
}

int main() {

  cin >> s;
  for(int i=0;i<101;i++) {
    fill(dp[i],dp[i]+1000,-1);
  }
  for(char c:s) {
    if(c == '0'){
      printf("YES\n0\n");
      return EXIT_SUCCESS;
    }
  }
  rec(0,0);
  if(!dp[0][0])
    printf("NO\n");

  return EXIT_SUCCESS;
}
