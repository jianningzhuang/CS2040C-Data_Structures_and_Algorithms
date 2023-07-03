#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> neighbours(int r, int c, vector<vector<int>> board, int n){
  vector<pair<int, int>> v;
  if (r + 2 < n && c + 1 < n && board[r+2][c+1] == 0){
    v.push_back({r+2, c+1});
  }
  if (r + 2 < n && c - 1 >= 0 && board[r+2][c-1] == 0){
    v.push_back({r+2, c-1});
  }
  if (r - 2 >= 0 && c - 1 >= 0 && board[r-2][c-1] == 0){
    v.push_back({r-2, c-1});
  }
  if (r - 2 >= 0 && c + 1 < n && board[r-2][c+1] == 0){
    v.push_back({r-2, c+1});
  }
  if (r - 1 >= 0 && c - 2 >= 0 && board[r-1][c-2] == 0){
    v.push_back({r-1, c-2});
  }
  if (r - 1 >= 0 && c + 2 < n && board[r-1][c+2] == 0){
    v.push_back({r-1, c+2});
  }
  if (r + 1 < n  && c - 2 >= 0 && board[r+1][c-2] == 0){
    v.push_back({r+1, c-2});
  }
  if (r + 1 < n && c + 2 < n && board[r+1][c+2] == 0){
    v.push_back({r+1, c+2});
  }
  return v;
}

bool not_loop(vector<pair<int, int>> v, pair<int, int> p){
  for (int i = 0; i < v.size(); i++){
    if (v[i] == p){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> board(n);
  int r, c;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    for (int j = 0; j < n; j++){
      if (line[j] == '.'){
        board[i].push_back(0);
      }
      else if (line[j] == '#'){
        board[i].push_back(1);
      }
      else if (line[j] == 'K'){
        r = i;
        c = j;
        board[i].push_back(1);
      }
    }
  }
  vector<pair<int, int>> initial;
  initial.push_back({r, c});
  queue<vector<pair<int, int>>> path_queue;
  path_queue.push(initial);
  while (path_queue.size() != 0){
    vector<pair<int, int>> temp = path_queue.front();
    path_queue.pop();
    pair<int, int> last_node;
    last_node = temp.back();
    if (last_node.first == 0 && last_node.second == 0){
      cout << temp.size() - 1 << endl;
      // for (auto &c : temp){
      //   cout << c.first << c.second << endl;
      // }
      return 0;
    }
    vector<pair<int, int>> next;
    next = neighbours(last_node.first, last_node.second, board, n);
    for (int k = 0; k < next.size(); k++){
      if (not_loop(temp, next[k])){
        vector<pair<int, int>> new_path = temp;
        new_path.push_back(next[k]);
        path_queue.push(new_path);
        board[next[k].first][next[k].second] = 1;
      }
    }
  }
  cout << -1 << endl;
}
