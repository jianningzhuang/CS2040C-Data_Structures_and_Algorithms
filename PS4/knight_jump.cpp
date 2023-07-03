#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<pair<int, int>>> neighbours(int n, vector<vector<int>> board){
  unordered_map<int, vector<pair<int, int>>> m;
  for (int r = 0; r < n; r++){
    for (int c = 0; c < n; c++){
      if (r + 2 < n && c + 1 < n && board[r+2][c+1] == 0){
        m[r*n + c].push_back({r+2, c+1});
      }
      if (r + 2 < n && c - 1 >= 0 && board[r+2][c-1] == 0){
        m[r*n + c].push_back({r+2, c-1});
      }
      if (r - 2 >= 0 && c - 1 >= 0 && board[r-2][c-1] == 0){
        m[r*n + c].push_back({r-2, c-1});
      }
      if (r - 2 >= 0 && c + 1 < n && board[r-2][c+1] == 0){
        m[r*n + c].push_back({r-2, c+1});
      }
      if (r - 1 >= 0 && c - 2 >= 0 && board[r-1][c-2] == 0){
        m[r*n + c].push_back({r-1, c-2});
      }
      if (r - 1 >= 0 && c + 2 < n && board[r-1][c+2] == 0){
        m[r*n + c].push_back({r-1, c+2});
      }
      if (r + 1 < n  && c - 2 >= 0 && board[r+1][c-2] == 0){
        m[r*n + c].push_back({r+1, c-2});
      }
      if (r + 1 < n && c + 2 < n && board[r+1][c+2] == 0){
        m[r*n + c].push_back({r+1, c+2});
      }
    }
  }
  return m;
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
  unordered_map<int, vector<pair<int, int>>> adj = neighbours(n, board);
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
    next = adj[(last_node.first)*n + last_node.second];
    for (int k = 0; k < next.size(); k++){
      if (not_loop(temp, next[k])){
        vector<pair<int, int>> new_path = temp;
        new_path.push_back(next[k]);
        path_queue.push(new_path);
      }
    }
  }
  cout << -1 << endl;
}
