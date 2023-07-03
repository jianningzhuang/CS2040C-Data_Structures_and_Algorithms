#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dc = {1, -1, 1, -1, 2, -2, 2, -2};
const int INF = 1e9;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, gr, gc, lr, lc;
  while (cin >> r){
    cin >> c >> gr >> gc >> lr >> lc;
    gr--;
    gc--;
    lr--;
    lc--;
    vector<vector<int>> board;
    for (int i = 0; i < r; i++){
      vector<int> temp;
      for (int j = 0; j < c; j++){
        temp.push_back(INF);
      }
      board.push_back(temp);
    }
    queue<pair<int, int>> pq;
    pq.push({gr, gc});
    board[gr][gc] = 0;
    while (!pq.empty()){
      pair<int, int> u = pq.front();
      pq.pop();
      int a = u.first;
      int b = u.second;
      //cout << a << b << endl;
      if (a == lr && b == lc){
        cout << board[a][b] << endl;
        break;
      }
      for (int k = 0; k < 8; k++){
        int rr = a + dr[k];
        int cc = b + dc[k];
        if (rr >= 0 && rr < r && cc >= 0 && cc < c){
          if (board[a][b] + 1 < board[rr][cc]){
            board[rr][cc] = board[a][b] + 1;
            pq.push({rr, cc});
          }
        }
      }
    }
    if (board[lr][lc] == INF){
      cout << "impossible\n";
    }
  }
}
