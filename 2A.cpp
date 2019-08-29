#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

unordered_map<string,list<pair<int,int>>> score_list;
unordered_map<string,int> score;
const int oo = 987654321;
int max_score = -oo;
string person;

int main() {
  int n;
  cin >> n;

  for(int i=0;i<n;i++) {
    string name;
    int point;
    cin >> name >> point;
    int &curr = score[name];
    curr = curr + point;
    score_list[name].push_back(make_pair(curr,i));
  }
  max_score = -oo;
  list<string> winners;
  for(auto& p:score) {
    if(max_score <= p.second) { 
      if(max_score < p.second)
        winners.clear();
      winners.push_back(p.first);
      max_score = p.second;
    }
  }
  string best;
  int when = oo;
  for(string& curr:winners) {
    list<pair<int,int>>& currlist = score_list[curr];
    for(auto& p:currlist) {
      if(p.first >= max_score && p.second < when) {
        when = p.second;
        best = curr;
        break;
      }
    }
  }
  cout << best << endl;

  return 0;
}
