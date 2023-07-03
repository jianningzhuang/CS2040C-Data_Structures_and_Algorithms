#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> board;
vector<pair<int, int>> numcc;
bool sea;
vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

void dfs(int r, int c){
  board[r][c] = '2';
  numcc.push_back({r, c});
  for (int i = 0; i < 4; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 0 && rr < n && cc >= 0 && cc < m && board[rr][cc] == '0'){
      if (rr == 0 || rr == n-1 || cc == 0 || cc == m-1){
        sea = true;
      }
      dfs(rr, cc);
    }
  }
}

int counting(int r, int c){
  int num = 0;
  for (int i = 0; i < 4; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 0 && rr < n && cc >= 0 && cc < m && board[rr][cc] == '1'){
      num++;
    }
  }
  return 4 - num;
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    board.push_back(line);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (board[i][j] == '0'){
        numcc.clear();
        sea = false;
        dfs(i, j);
        if (!sea){
          for (auto &p : numcc){
            int rrr = p.first;
            int ccc = p.second;
            board[rrr][ccc] = '1';
          }
        }
      }
    }
  }
  int result = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (board[i][j] == '1'){
        int temp = counting(i, j);
        result += temp;
      }
    }
  }
  cout << result << endl;
}
