#include <bits/stdc++.h>

using namespace std;

string s,t;

int t_alpha[26];
int s_alpha[26];


int possible(int cnt,int q) {
  for(int i=0;i<26;i++) {
    long long need = static_cast<long long>(t_alpha[i]) * static_cast<long long>(cnt) - s_alpha[i];
    if(need < 0) continue;
    if(need > 0 && q < need)
      return false; 
    else 
      q = q - need;
  }
  return true;
} 

int binarySearch(int low,int high, int q) {
  if(low >=high) {
    return low;
  }
  int mid = low + (high - low) / 2;
  if(possible(mid+1,q)) {
    return binarySearch(mid+1, high, q);
  }
  return binarySearch(low,mid,q);
}

int main() {
  cin >> s >> t;
  for(char c:t) {
    int idx = c - 'a';
    t_alpha[idx]++;
  }
  int q = 0;
  for(char c:s) {
    if(c == '?') {
      q++;
      continue;
    }
    int idx = c - 'a';
    s_alpha[idx]++;
  }

  if(t.length() > s.length()) {
    cout << s << "\n";
    return 0;
  }
  int suitability = binarySearch(0,s.length(),q);
  //cout << suitability << "\n";
  int need[26];
  for(int i = 0; i < 26 ;i++) {
    need[i] = 0;
    int curr_need = t_alpha[i] * suitability - s_alpha[i]; 
    if(curr_need <= 0) continue;
    need[i] = curr_need;
  }
  int i = 0;
  int j = 0;
  while(j < s.length()) {
    if(s[j] != '?') {
      j++;
      continue;
    }
    if(i >= 26) {
      s[j] = 'a';
      j++;
      continue;
    }
    if(need[i] > 0) {
      //cout << i << " " << need[i] << "\n";
      s[j] = static_cast<char>(i + 'a');
      need[i]--;
      j++;
    } else {
      if(i < 26)
        i++;
    }
  }
  cout << s << "\n";
}
