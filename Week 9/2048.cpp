#include <bits/stdc++.h>
using namespace std;

void printgrid(vector<vector<int>> board){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  vector<vector<int>> board(4);
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      int grid;
      cin >> grid;
      board[i].push_back(grid);
    }
  }
  int cmd;
  cin >> cmd;
  if (cmd == 0){
    for (int i = 0; i < 4; i++){
      int curr = 0;
      for (int j = 1; j < 4; j++){
        if (board[i][j] != 0){
          if (board[i][curr] == 0){
            board[i][curr] = board[i][j];
            board[i][j] = 0;
          }
          else if (board[i][j] == board[i][curr]){
            board[i][curr] *= 2;
            curr++;
            board[i][j] = 0;
          }
          else{
            curr++;
            if (curr != j){
              board[i][curr] = board[i][j];
              board[i][j] = 0;
            }
          }
        }
      }
    }
    printgrid(board);
  }
  else if (cmd == 1){
    for (int i = 0; i < 4; i++){
      int curr = 0;
      for (int j = 1; j < 4; j++){
        if (board[j][i] != 0){
          if (board[curr][i] == 0){
            board[curr][i] = board[j][i];
            board[j][i] = 0;
          }
          else if (board[j][i] == board[curr][i]){
            board[curr][i] *= 2;
            curr++;
            board[j][i] = 0;
          }
          else{
            curr++;
            if (curr != j){
              board[curr][i] = board[j][i];
              board[j][i] = 0;
            }
          }
        }
      }
    }
    printgrid(board);
  }
  else if (cmd == 2){
    for (int i = 0; i < 4; i++){
      int curr = 3;
      for (int j = 2; j >= 0; j--){
        if (board[i][j] != 0){
          if (board[i][curr] == 0){
            board[i][curr] = board[i][j];
            board[i][j] = 0;
          }
          else if (board[i][j] == board[i][curr]){
            board[i][curr] *= 2;
            curr--;
            board[i][j] = 0;
          }
          else{
            curr--;
            if (curr != j){
              board[i][curr] = board[i][j];
              board[i][j] = 0;
            }
          }
        }
      }
    }
    printgrid(board);
  }
  else if (cmd == 3){
    for (int i = 0; i < 4; i++){
      int curr = 3;
      for (int j = 2; j >= 0; j--){
        if (board[j][i] != 0){
          if (board[curr][i] == 0){
            board[curr][i] = board[j][i];
            board[j][i] = 0;
          }
          else if (board[j][i] == board[curr][i]){
            board[curr][i] *= 2;
            curr--;
            board[j][i] = 0;
          }
          else{
            curr--;
            if (curr != j){
              board[curr][i] = board[j][i];
              board[j][i] = 0;
            }
          }
        }
      }
    }
    printgrid(board);
  }
}
