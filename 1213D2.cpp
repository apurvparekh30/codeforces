#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 * 2 + 1;

int cnt[MAX];
int arr[MAX];
int moves[MAX];

int main() {
  int n,k; cin >> n >> k;
  int steps = -1;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
    if(cnt[arr[i]] >= k) {
      steps = 0;
    }
  }

  if(steps == 0) {
    cout << "0\n";
    return 0;
  }

  int min_moves = 987654321;

  for(int steps = 1; steps <= 20; steps++) {
    for(int i=0;i<n;i++) {
      if(arr[i] == 0) continue;
      arr[i] = arr[i] / 2;
      cnt[arr[i]]++;
      moves[arr[i]] += steps;
      if(cnt[arr[i]] >= k) {
        min_moves = min(min_moves, moves[arr[i]]);
      }
    } 
  }
  cout << min_moves << "\n";
  return 0;
}
