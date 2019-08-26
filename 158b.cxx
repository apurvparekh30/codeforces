#include <bits/stdc++.h>
#define in cin>>
#define out cout<<

using namespace std;
  int ans = 0;

int main()
{
  int n;
  in(n);
  vector<int> group(n);



  for(int i=0;i<n;i++)
    in(group[i]);

  sort(group.begin(),group.end());
  int cab = 0;
  int j = n - 1;
  int i = 0;
  while(i!=j) {
    if(group[j]+group[i]<=4) {
      group[j]+=group[i];
      i++;
    }
    else {
      cab++;
      j--;
    }
  }
  cout<<cab+1<<endl;
  return 0;
}
