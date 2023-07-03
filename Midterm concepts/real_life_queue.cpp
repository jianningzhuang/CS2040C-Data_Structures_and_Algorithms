#include <bits/stdc++.h>
using namespace std;


bool finding(vector<unordered_set<int>> teams, int a, int b){
  for (int i = 0; i < teams.size(); i++){
    if (teams[i].find(a) !=  teams[i].end() && teams[i].find(b) !=  teams[i].end()){
      return true;
    }
  }
  return false;
}

void RLEnqueue(vector<vector<int>> queue, vector<unordered_set<int>> teams, int ID){
  for (int i = 0; i < queue.size(); i++){
    if (finding(teams, queue[i][0], ID)){
      queue[i].push_back(ID);
      return;
    }
  }
  queue.push_back({ID});
}

int RLDequeue(vector<vector<int>> queue){
  int first = queue[0][0];
  queue[0].erase(queue[0].begin());
  if (queue[0].empty()){
    queue.erase(queue.begin());
  }
  return first;
}

int main(){
  int t;
  cin >> t;
  vector<vector<int>> queue;
  vector<unordered_set<int>> teams;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    unordered_set<int> s;
    while (k--){
      int ID;
      cin >> ID;
      s.insert(ID);
    }
    teams.push_back(s);
  }
  int cmd;
  while (cin >> cmd, cmd != 3){
    if (cmd == 1){
      int ID;
      cin >> ID;
      RLEnqueue(queue, teams, ID);
    }
    else{
      cout << RLDequeue(queue) << endl;
    }
  }
  return 0;
}
