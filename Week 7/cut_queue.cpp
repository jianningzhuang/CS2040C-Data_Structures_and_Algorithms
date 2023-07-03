#include <bits/stdc++.h>
using namespace std;

// 4:20 to 4:37

vector<vector<int>> queue1;
vector<unordered_set<int>> teams;

bool find_team(int a, int b){
  for (int i = 0; i < teams.size(); i++){
    if (teams[i].find(a) != teams[i].end() && teams[i].find(b) != teams[i].end()){
      return true;
    }
  }
  return false;
}

void RLEnqueue(int ID){
  for (int i = 0; i < queue1.size(); i++){
    if (find_team(queue1[i][0], ID)){
      queue1[i].push_back(ID);
      return;
    }
  }
  vector<int> n;
  n.push_back(ID);
  queue1.push_back(n);
}

int RLDequeue(){
  int byebye = queue1[0][0];
  queue1[0].erase(queue1[0].begin());
  if (queue1[0].empty()){
    queue1.erase(queue1.begin());
  }
  return byebye;

}

int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    unordered_set<int> s;
    for (int j = 0; j < k; j++){
      int temp;
      cin >> temp;
      s.insert(temp);
    }
    teams.push_back(s);
  }
  int cmd;
  while (cin >> cmd, cmd != 3){
    if (cmd == 1){
      int ID; cin >> ID;
      RLEnqueue(ID);
    }
    else{
      cout << RLDequeue() << endl;
    }
  }
}
