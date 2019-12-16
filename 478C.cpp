#include <bits/stdc++.h>

using namespace std;

vector<long long> nums;

int main() {
  for(int i=0;i<3;i++){
    long long tmp; cin >> tmp;
    nums.push_back(tmp);
  }
  sort(nums.begin(),nums.end());
  long long sum = nums[0] + nums[1];
  if(nums[2] <= (sum * 2L))
  {
    sum = (sum + nums[2]) / 3L;   
  }
  cout << sum << "\n";
  return 0;
}
