#include <bits/stdc++.h>
using namespace std;

vector<string> board;
bool found = false;
vector<int> dr = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dc = {1, -1, 1, -1, 2, -2, 2, -2};
string icpc = "ICPCASIASG";

bool bfs(int r, int c, int n){
  vector<pair<int, int>> initial;
  initial.push_back({r, c});
  queue<vector<pair<int, int>>> pq;
  pq.push(initial);
  while (pq.size() != 0){
    vector<pair<int, int>> temp = pq.front();
    pq.pop();
    pair<int, int> last_node;
    last_node = temp.back();
    if (board[last_node.first][last_node.second] == 'G'){
      return true;
    }
    for (int i = 0; i < 8; i++){
      int rr = last_node.first + dr[i];
      int cc = last_node.second + dc[i];
      if (rr >= 0 && rr < n && cc >= 0 && cc < n){
        if (board[rr][cc] == icpc[temp.size()]){
          //cout << board[rr][cc] << temp.size() << endl;
          vector<pair<int, int>> new_path = temp;
          new_path.push_back({rr, cc});
          pq.push(new_path);
        }
      }
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string curr = "";
    for (int j = 0; j < n; j++){
      char grid;
      cin >> grid;
      curr += grid;
    }
    board.push_back(curr);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (board[i][j] == 'I'){
        found = bfs(i, j, n);
        if (found){
          cout << "YES\n";
          return 0;
        }
      }
    }
  }
  cout << "NO\n";
  return 0;
}
