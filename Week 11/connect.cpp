#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<vector<char>> board;
bool blue = false;
bool red = false;

void horizb(int r, int c, int x, int y, int n){
  int len = -1;
  int temp = c;
  while (temp < y && board[r][temp] == 'B'){
    len++;
    temp++;
  }
  temp = c;
  while (temp >= 0 && board[r][temp] == 'B'){
    len++;
    temp--;
  }
  if (len >= n){
    blue = true;
  }
}

void vertb(int r, int c, int x, int y, int n){
  int len = -1;
  int temp = r;
  while (temp < x && board[temp][c] == 'B'){
    len++;
    temp++;
  }
  temp = c;
  while (temp >= 0 && board[temp][c] == 'B'){
    len++;
    temp--;
  }
  if (len >= n){
    blue = true;
  }
}

void diag1b(int r, int c, int x, int y, int n){
  int len = -1;
  int tempr = r;
  int tempc = c;
  while (tempr < x && tempc < y && board[tempr][tempc] == 'B'){
    len++;
    tempr++;
    tempc++;
  }
  tempr = r;
  tempc = c;
  while (tempr >= 0 && tempc >= 0 && board[tempr][tempc] == 'B'){
    len++;
    tempr--;
    tempc--;
  }
  if (len >= n){
    blue = true;
  }
}

void diag2b(int r, int c, int x, int y, int n){
  int len = -1;
  int tempr = r;
  int tempc = c;
  while (tempr < x && tempc >= 0 && board[tempr][tempc] == 'B'){
    len++;
    tempr++;
    tempc--;
  }
  tempr = r;
  tempc = c;
  while (tempr >= 0 && tempc < y && board[tempr][tempc] == 'B'){
    len++;
    tempr--;
    tempc++;
  }
  if (len >= n){
    blue = true;
  }
}

void horizr(int r, int c, int x, int y, int n){
  int len = -1;
  int temp = c;
  while (temp < y && board[r][temp] == 'R'){
    len++;
    temp++;
  }
  temp = c;
  while (temp >= 0 && board[r][temp] == 'R'){
    len++;
    temp--;
  }
  if (len >= n){
    red = true;
  }
}

void vertr(int r, int c, int x, int y, int n){
  int len = -1;
  int temp = r;
  while (temp < x && board[temp][c] == 'R'){
    len++;
    temp++;
  }
  temp = c;
  while (temp >= 0 && board[temp][c] == 'R'){
    len++;
    temp--;
  }
  if (len >= n){
    red = true;
  }
}

void diag1r(int r, int c, int x, int y, int n){
  int len = -1;
  int tempr = r;
  int tempc = c;
  while (tempr < x && tempc < y && board[tempr][tempc] == 'R'){
    len++;
    tempr++;
    tempc++;
  }
  tempr = r;
  tempc = c;
  while (tempr >= 0 && tempc >= 0 && board[tempr][tempc] == 'R'){
    len++;
    tempr--;
    tempc--;
  }
  if (len >= n){
    red = true;
  }
}

void diag2r(int r, int c, int x, int y, int n){
  int len = -1;
  int tempr = r;
  int tempc = c;
  while (tempr < x && tempc >= 0 && board[tempr][tempc] == 'R'){
    len++;
    tempr++;
    tempc--;
  }
  tempr = r;
  tempc = c;
  while (tempr >= 0 && tempc < y && board[tempr][tempc] == 'R'){
    len++;
    tempr--;
    tempc++;
  }
  if (len >= n){
    red = true;
  }
}

void checkblue(int r, int c, int x, int y, int n){
  horizb(r, c, x, y, n);
  vertb(r, c, x, y, n);
  diag1b(r, c, x, y, n);
  diag2b(r, c, x, y, n);
}

void checkred(int r, int c, int x, int y, int n){
  horizr(r, c, x, y, n);
  vertr(r, c, x, y, n);
  diag1r(r, c, x, y, n);
  diag2r(r, c, x, y, n);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y, n;
  cin >> x >> y >> n;
  board.assign(x, vector<char>());
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      char piece;
      cin >> piece;
      board[i].push_back(piece);
    }
  }
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      if (board[i][j] == 'B'){
        checkblue(i, j, x, y, n);
      }
      else if (board[i][j] == 'R'){
        checkred(i, j, x, y, n);
      }
    }
    if (blue){
      cout << "BLUE WINS\n";
      return 0;
    }
    else if (red){
      cout << "RED WINS\n";
      return 0;
    }
  }
  cout << "NONE\n";
  return 0;
}
