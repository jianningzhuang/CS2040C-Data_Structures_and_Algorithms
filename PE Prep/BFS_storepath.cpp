#include <bits/stdc++.h>
using namespace std;

vector<string> board;
vector<int> dr = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dc = {1, -1, 1, -1, 2, -2, 2, -2};

bool not_loop(vector<pair<int, int>> v, pair<int, int> p){
  for (int i = 0; i < v.size(); i++){
    if (v[i] == p){
      return false;
    }
  }
  return true;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    board.push_back(line);
  }
  int r;
  int c;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (board[i][j] == 'K'){
        r = i;
        c = j;
      }
    }
  }
  vector<pair<int, int>> initial;
  initial.push_back({r, c});
  queue<vector<pair<int, int>>> pq;
  pq.push(initial);
  while (!pq.empty()){
    vector<pair<int, int>> temp = pq.front();
    pq.pop();
    pair<int, int> last_node = temp.back();
    board[last_node.first][last_node.second] = '#';
    if (last_node.first == 0 && last_node.second == 0){
      cout << temp.size() - 1 << endl;
      return 0;
    }
    for (int k = 0; k < 8; k++){
      int rr = last_node.first + dr[k];
      int cc = last_node.second + dc[k];
      if (rr >= 0 && rr < r && cc >= 0 && cc < c && board[rr][cc] == '.'){
        if (not_loop(temp, {rr, cc})){
          vector<pair<int, int>> new_path = temp;
          new_path.push_back({rr, cc});
          pq.push(new_path);
          board[rr][cc] = '#';
        }
      }
    }
  }
  cout << -1 << endl;
}
