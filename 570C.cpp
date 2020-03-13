#include <bits/stdc++.h>

using namespace std;

int n,m;
string str;

bool isAlpha(char c) { return c>='a' && c<='z';}

void adjustSize(int left,int right, int& size) {
  if(str[left] == '.') size++;
  if(str[right] == '.') size++;
}

int main() {
  cin >> n >> m;
  cin >> str;
  int m_len = str.length();
  int m_left[m_len];
  int m_right[m_len]; 
  m_left[0] = 0;
  for(int i=1; i<m_len; i++) {
    if(isAlpha(str[i-1])) m_left[i] = i - 1;
    else m_left[i] = m_left[i-1];
  }
  m_right[m_len-1] = m_len-1;
  for(int i=m_len-2; i>=0; i--) {
    if(isAlpha(str[i+1])) m_right[i] = i + 1;
    else m_right[i] = m_right[i+1];
  }
  int ans = 0;
  for(int i=0;i<m_len-1;) {
    int r = m_right[i];
    int size = (r - i) - 1;
    adjustSize(i,r,size);
    //cout << i << " " << r << " " << size << "\n";
    if(size > 1)
      ans = ans + (size - 1);
    i = r;
  }

  cout << ans << "\n";

  while(m--) {
    int idx; cin >> idx; idx--;
    char c; cin >> c;
    if((isAlpha(c) && isAlpha(str[idx])) || (!isAlpha(c) && !isAlpha(str[idx]))) continue;
    if(isAlpha(c)) {
      int temp = m_right[idx] - m_left[idx] - 1;
      adjustSize(m_left[idx], m_right[idx], temp);
      if(temp > 1)
        ans = ans - (temp - 1);
      str[idx] = c;
      int m_right_size = m_right[idx] - idx - 1;
      adjustSize(idx, m_right[idx], m_right_size);
      int m_left_size = idx - m_left[idx] - 1;
      adjustSize(m_left[idx],idx, m_left_size);
      if(m_right_size > 1)
        ans = ans + (m_right_size - 1);
      if(m_left_size > 1)
        ans = ans + (m_left_size - 1);
    } else {
      int m_right_size = m_right[idx] - idx - 1;
      adjustSize(idx, m_right[idx], m_right_size);
      int m_left_size = idx - m_left[idx] - 1;
      adjustSize(m_left[idx],idx, m_left_size);    
      if(m_right_size > 1)
        ans = ans - (m_right_size - 1);
      if(m_left_size > 1)
        ans = ans - (m_left_size - 1);
      str[idx] = c;
      int temp = m_right[idx] - m_left[idx] - 1;
      adjustSize(m_left[idx], m_right[idx], temp);
      if(temp > 1)
        ans = ans + temp + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
