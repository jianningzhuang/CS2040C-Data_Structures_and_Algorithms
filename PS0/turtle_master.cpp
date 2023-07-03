#include <bits/stdc++.h>
using namespace std;

int main(){
  string board[8];
  for (int i = 0; i < 8; i++){
    string line;
    cin >> line;
    board[i] = line;
  }
  string command;
  cin >> command;
  pair<int, int> current(7,0);
  pair<int, int> direction(0,1);
  bool bug = false;
  for (auto &c: command){
    if (c == 'F'){
      current.first += direction.first;
      current.second += direction.second;
      if (current.first < 0 || current.first >= 8 || current.second < 0 || current.second >= 8 || board[current.first][current.second] == 'C' || board[current.first][current.second] == 'I'){
        bug = true;
        break;
      }
    }
    else if (c == 'R'){
      if (direction.first == 0 && direction.second == 1){
        direction.first = 1;
        direction.second = 0;
      }
      else if (direction.first == 1 && direction.second == 0){
        direction.first = 0;
        direction.second = -1;
      }
      else if (direction.first == 0 && direction.second == -1){
        direction.first = -1;
        direction.second = 0;
      }
      else if (direction.first == -1 && direction.second == 0){
        direction.first = 0;
        direction.second = 1;
      }
    }
    else if (c == 'L'){
      if (direction.first == 0 && direction.second == 1){
        direction.first = -1;
        direction.second = 0;
      }
      else if (direction.first == -1 && direction.second == 0){
        direction.first = 0;
        direction.second = -1;
      }
      else if (direction.first == 0 && direction.second == -1){
        direction.first = 1;
        direction.second = 0;
      }
      else if (direction.first == 1 && direction.second == 0){
        direction.first = 0;
        direction.second = 1;
      }
    }
    else if (c == 'X'){
      int tempx = current.first;
      int tempy = current.second;
      tempx += direction.first;
      tempy += direction.second;
      if (tempx < 0 || tempx >= 8 || tempy < 0 || tempy >= 8 || board[tempx][tempy] == '.' || board[tempx][tempy] == 'C'){
        bug = true;
        break;
      }
      else{
        board[tempx][tempy] = '.';
      }
    }
  }
  if (bug == false && board[current.first][current.second] == 'D'){
    cout << "Diamond!\n";
  }
  else{
    cout << "Bug!\n";
  }
}
