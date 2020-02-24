#include <bits/stdc++.h>

using namespace std;

int n,m,d;
pair<int,int> times[2 * 100000 + 1];
int days[2 * 100000 + 1];

int binarySearch(int low,int high, int next_time) {
  if(low >= high) {
    if(low == high) {
      if(times[low].first >= next_time ) {
        while(days[times[low].second] != 0 && low < n) low++;
        if(low == n) return -1;
        return times[low].second;
      }
    }
    return -1;
  }
  int mid = low + (high - low) / 2;
  if(times[mid].first >= next_time) {
    return binarySearch(low,mid,next_time);
  }
  return binarySearch(mid+1, high, next_time);
}

int main() {
  cin >> n >> m >> d;
  for(int i=0;i<n;i++) {
    int no; cin >> no;
    times[i] = make_pair(no, i);
  }
  sort(times,times + n);
  int day = 0;
  for(int i=0; i<n; i++) {
    if(days[times[i].second] == 0) {
      day++;
      days[times[i].second] = day;
    }
    int curr_time = times[i].first;
    int next_time_idx = binarySearch(i, n-1, curr_time + d + 1);
    if(next_time_idx != -1)
      days[next_time_idx] = days[times[i].second];
  }
  cout << day << "\n";
  for(int i=0; i<n ; i++) {
    cout << days[i] << " "; 
  }
  cout << "\n";
  return 0;
}
