#include <bits/stdc++.h>
using namespace std;

vector<string> board;

vector<pair<int, int>> adj = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void floodfill(int r, int c, int n, int m){
  vector<pair<int, int>> cc;
  queue<pair<int, int>> q;
  q.push({r, c});
  cc.push_back({r, c});
  board[r][c] = '2';
  bool sea = false;
  while (!q.empty()){
    pair<int, int> u = q.front();
    q.pop();
    for (auto &p : adj){
      int i = u.first + p.first;
      int j = u.second + p.second;
      if (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == '0'){
        board[i][j] = '2';
        cc.push_back({i, j});
        q.push({i, j});
        if (i == 0 || i == n - 1 || j == 0 || j == m-1){
          sea = true;
        }
      }
    }
  }
  if (!sea){
    for (auto &p1 : cc){
      int i = p1.first;
      int j = p1.second;
      board[i][j] = '1';
    }
  }
}

int black(int r, int c, int n, int m){
  int num = 0;
  for (auto &p : adj){
    int i = r + p.first;
    int j = c + p.second;
    if (i < 0 || i >= n || j < 0 || j >= m){
      num++;
    }
    else if (board[i][j] == '2'){
      num++;
    }
  }
  //cout << num << endl;
  return num;
}

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    board.push_back(line);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (board[i][j] == '0'){
        floodfill(i, j, n, m);
      }
    }
  }
  // for (int i = 0; i < n; i++){
  //   cout << board[i] << endl;
  // }
  int result = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (board[i][j] == '1'){
        result += black(i, j, n, m);
      }
    }
  }
  cout << result << endl;
}
