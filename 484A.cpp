#include <bits/stdc++.h>

using namespace std;

const uint64_t ONE = 1LL;

int log2_(uint64_t no) {
  //cout << static_cast<uint64_t>(log2l(static_cast<long double>(no))) << "\n";
  return static_cast<int>(log2l(static_cast<long double>(no)));
}

uint64_t rec(uint64_t l, uint64_t r) {
  int r_log = log2_(r);
  int64_t two_power = (ONE << r_log) - ONE;
  int64_t two_power_next = two_power * 2 + ONE;

  if(two_power_next <= r) return two_power_next;
  if(two_power >= l) return two_power;
  //cout << "hello\n";
  // we turn of the msb
  // the number is between two powers means msb is same
  // like 8 to 14, 16 to 30
  return (ONE << r_log) | rec(l & (~(ONE << r_log)), r & (~(ONE << r_log)));
}

int main() {
  int n;
  cin >> n;
  uint64_t left, right;
  //cout << log2_(11) << "\n"; 
  while(n--) {
    cin >> left >> right;
    uint64_t ans = rec(left, right);
    cout << ans << "\n";
  }
  return 0;
}
