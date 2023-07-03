#include <bits/stdc++.h>
using namespace std;

//start 1025 to

vector<vector<int>> board;

int deci1 = 3;
int bina1 = 2;

vector<pair<int, int>> adj = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

void decimalfill(int i, int j, int r, int c){
  board[i][j] = deci1;
  queue<pair<int, int>> q;
  q.push({i, j});
  while (!q.empty()){
    pair<int, int> p = q.front();
    q.pop();
    for (auto &p1 : adj){
      int i1 = p.first + p1.first;
      int j1 = p.second + p1.second;
      if (i1 >= 0 && i1 < r && j1 >= 0 && j1 < c && board[i1][j1] == 1){
        board[i1][j1] = deci1;
        q.push({i1, j1});
      }
    }
  }
  deci1 += 2;
}

void binaryfill(int i, int j, int r, int c){
  board[i][j] = bina1;
  queue<pair<int, int>> q;
  q.push({i, j});
  while (!q.empty()){
    pair<int, int> p = q.front();
    q.pop();
    for (auto &p1 : adj){
      int i1 = p.first + p1.first;
      int j1 = p.second + p1.second;
      if (i1 >= 0 && i1 < r && j1 >= 0 && j1 < c && board[i1][j1] == 0){
        board[i1][j1] = bina1;
        q.push({i1, j1});
      }
    }
  }
  bina1 += 2;
}

void printboard(){
  for (int i = 0; i < board.size(); i++){
    for (int j = 0; j < board[i].size(); j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}

int main(){
  int r, c;
  cin >> r >> c;
  board.assign(r, vector<int>());
  for (int i = 0; i < r; i++){
    string line;
    cin >> line;
    for (auto &c1 : line){
      board[i].push_back(int(c1) - int('0'));
    }
  }
  //printboard();
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (board[i][j] == 1){
        decimalfill(i, j, r, c);
      }
      else if (board[i][j] == 0){
        binaryfill(i, j, r, c);
      }
    }
  }
  //printboard();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    if (board[r1][c1] == board[r2][c2]){
      if ((board[r2][c2])%2 == 1){
        cout << "decimal" << endl;
      }
      else{
        cout << "binary" << endl;
      }
    }
    else{
      cout << "neither" << endl;
    }
    //cout << board[r1][c1] << " to " << board[r2][c2] << endl;
  }
}
