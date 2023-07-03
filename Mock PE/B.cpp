#include <bits/stdc++.h>
using namespace std;

vector<string> board;
int count1 = 0;
vector<pair<int, int>> next1 = {{1,0}, {1, -1}, {0, -1}, {-1, -1}, { -1, 0}, {-1, 1}, {0, 1}, {1, 1}};

pair<int, int> adj(int r, int c, int m, int n){
  for (auto &p : next1){
    int a = p.first;
    int b = p.second;
    if (r + a >= 0 && c + b >= 0 && r + a < m && c + b < n && board[r + a][c + b] == '#'){
      board[r + a][c + b] = '.';
      return {r + a, c + b};
    }
  }
  return {-1, -1};
}

void loop(int r, int c, int m, int n){
  int i = r;
  int j = c;
  board[i][j] = '.';
  bool flag = true;
  while (flag){
    pair<int, int> temp = adj(i, j, m, n);
    if (temp.first == -1 && temp.second == -1){
      flag = false;
      for (auto &p : next1){
        if (i + p.first == r && j + p.second == c){
          count1++;
        }
      }
    }
    else{
      i = temp.first;
      j = temp.second;
    }
  }
}

int main(){
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++){
    string line;
    cin >> line;
    board.push_back(line);
  }
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      if (board[i][j] == '#'){
        loop(i, j, m, n);
      }
    }
  }
  cout << count1 << endl;
}
