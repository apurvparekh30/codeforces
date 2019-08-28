#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<long long,long long>> friends;

int n,d;

int main() {
  cin >> n >> d;
  for(int i=0;i<n;i++) {
    pair<long long,long long> p;
    cin >> p.first >> p.second;
    friends.push_back(p);
  }
  sort(friends.begin(),friends.end());
  long long curr = friends[0].second;
  long long best = friends[0].second;
  long long low = 0;
  for(int i=1;i<n;) {
    if(friends[i].first - friends[low].first >= d) {
      curr = curr - friends[low].second;
      low++;
    }
    else {
      curr = curr + friends[i].second;
      i++;
    }
    if(best < curr) {
      best = curr;
    }
  }
  cout << best << endl;
}
