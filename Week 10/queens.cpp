#include <bits/stdc++.h>
using namespace std;

bool valid(int r, int c, vector<vector<int>> board){
  for (int i = 0; i < 8; i++){
    if (board[r][i] == 1 && i != c){
      return false;
    }
    if (board[i][c] == 1 && i != r){
      return false;
    }
  }
  int i = r + 1;
  int j = c + 1;
  while (i < 8 && j < 8){
    if (board[i][j] == 1){
      return false;
    }
    i++;
    j++;
  }
  i = r + 1;
  j = c - 1;
  while (i < 8 && j >= 0){
    if (board[i][j] == 1){
      return false;
    }
    i++;
    j--;
  }
  i = r - 1;
  j = c - 1;
  while (i >= 0 && j >= 0){
    if (board[i][j] == 1){
      return false;
    }
    i--;
    j--;
  }
  i = r - 1;
  j = c + 1;
  while (i >= 0 && j < 8){
    if (board[i][j] == 1){
      return false;
    }
    i--;
    j++;
  }
  return true;
}

int main(){
  vector<vector<int>> board(8);
  int count = 0;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      char grid;
      cin >> grid;
      if (grid == '*'){
        count++;
        board[i].push_back(1);
      }
      else{
        board[i].push_back(0);
      }
    }
  }
  if (count != 8){
    cout << "invalid";
    return 0;
  }
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (board[i][j] == 1){
        if (!valid(i, j, board)){
          cout << "invalid";
          return 0;
        }
      }
    }
  }
  cout << "valid";
}
