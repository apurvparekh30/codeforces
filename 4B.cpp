#include <bits/stdc++.h>

using namespace std;

int d,need;
vector<int> minhr;
vector<int> maxhr;

int main() {
  cin>>d>>need;
  int minSum = 0;
  int maxSum = 0;
  for(int i=0;i<d;i++) {
    int mn,mx;
    cin >> mn >> mx;
    minSum += mn;
    maxSum += mx;
    minhr.push_back(mn);
    maxhr.push_back(mx);
  }
  if(need < minSum || need > maxSum) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" <<endl;
  need = need - minSum;
  for(int i=0;i<d;i++) {
    if(need + minhr[i] > maxhr[i]) {
      need = (need + minhr[i]) - maxhr[i];
      minhr[i] = maxhr[i];
    }
    else {
      need = (need + minhr[i]);
      minhr[i] = need;
      break;
    }
  }
  bool space = false;
  for(int i=0;i<minhr.size();i++) {
    if(space) cout << " ";
    space = true;
    cout<<minhr[i];
  }
  cout << endl;
  return 0;
}
