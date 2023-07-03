#include <bits/stdc++.h>
using namespace std;

vector<string> board;
int w, h;


int find(int r, int c){
  int here = 0;
  if (board[r][c] == '#' || board[r][c] == 'V'){
    return 0;
  }
  else if (board[r][c] == 'G'){
    here = 1;
  }
  board[r][c] = 'V';
  if (board[r+1][c] == 'T' || board[r-1][c] == 'T' || board[r][c+1] == 'T' || board[r][c-1] == 'T'){
    return here;
  }
  else{
    here += find(r - 1,c) + find(r+1, c) + find(r, c-1) + find(r, c+1);
    return here;
  }

}

int main(){
  cin >> w >> h;
  for (int i = 0; i < h; i++){
    string line;
    cin >> line;
    board.push_back(line);
  }
  int gold = 0;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (board[i][j] == 'P'){
        gold += find(i,j);
      }
    }
  }
  //printboard();
  cout << gold << endl;
}
