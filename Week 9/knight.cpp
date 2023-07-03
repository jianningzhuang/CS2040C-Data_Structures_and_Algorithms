#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<char>> board(n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      char grid;
      cin >> grid;
      board[i].push_back(grid);
      cout << board[i][j] << endl;
    }
  }
}
