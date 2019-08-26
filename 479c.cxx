#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
  vector<pair<int,int>> vect;
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int a,b;
    cin >> a >> b;
    vect.push_back(make_pair(a,b));
  }
  sort(vect.begin(),vect.end());
  int best = -1;
  for(int i=0;i<n;i++) {
    auto& curr = vect[i];
    int temp = min(curr.first,curr.second);
    if(temp < best) {
      best = max(curr.first,curr.second);
    }
    else {
      best = temp;
    }
  }
  cout << best << endl;
  return 0;
}
