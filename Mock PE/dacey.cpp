#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> start1;
pair<int, int> end1;
vector<string> board;
unordered_map<string, int> state;
vector<vector<unordered_set<int>>> adj;

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    cin >> n;
    board.clear();
    for (int j = 0; j < n; j++){
      string line;
      cin >> line;
      int k = 0;
      for (auto &c : line){
        if (c == 'S'){
          start1 = {j, k};
        }
        else if (c == 'H'){
          end1 = {j, k};
        }
        k++;
      }
      board.push_back(line);
    }
    state["up"] = 4;
    state["down"] = 3;
    state["left"] = 5;
    state["right"] = 2;
    state["top"] = 1;
    state["bottom"] = 6;
    dfs(start);
  }
}
