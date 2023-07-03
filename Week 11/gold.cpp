#include <bits/stdc++.h>
using namespace std;

//start 4:12

vector<string> board;
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, 1, -1};
int w, h;
int numgold = 0;

void printboard(){
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}

void marktrap(int r, int c){
  board[r][c] = 'A';
  for (int i = 0; i < 4; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 1 && rr < h - 1 && cc >= 1 && cc < w - 1){
      if (board[rr][cc] == '.'){
        board[rr][cc] = 'A';
      }
      else if (board[rr][cc] == 'G'){
        board[rr][cc] = 'Y';
      }
      else if (board[rr][cc] == 'P'){
        board[rr][cc] = 'A';
      }
    }
  }
}

void dfs(int r, int c){
  board[r][c] = 'A';
  for (int i = 0; i < 4; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 1 && rr < h - 1 && cc >= 1 && cc < w - 1){
      if (board[rr][cc] == '.'){
        dfs(rr, cc);
      }
      else if (board[rr][cc] == 'G'){
        numgold++;
        dfs(rr, cc);
      }
      else if (board[rr][cc] == 'Y'){
        board[rr][cc] = 'B';
        numgold++;
      }
    }
  }
}

int main(){
  cin >> w >> h;
  for (int i = 0; i < h; i++){
    string line;
    cin >> line;
    board.push_back(line);
  }
  for (int i = 1; i < h - 1; i++){
    for (int j = 1; j < w - 1; j++){
      if (board[i][j] == 'T'){
        marktrap(i, j);
      }
    }
  }
  //printboard();
  for (int i = 1; i < h - 1; i++){
    for (int j = 1; j < w - 1; j++){
      if (board[i][j] == 'P'){
        dfs(i, j);
      }
    }
  }
  //printboard();
  cout << numgold << endl;
}
