#include <bits/stdc++.h>
using namespace std;

vector<string> board;
vector<int> dr = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dc = {1, -1, 1, -1, 2, -2, 2, -2};
unordered_map<int, int> parent;

int bfs(int r, int c, int n){
  int result = -1;
  queue<pair<int, int>> pq;
  pq.push({r, c});
  parent[r*100 + c] = -1;
  while (!pq.empty()){
    pair<int, int> u = pq.front();
    pq.pop();
    int i = u.first;
    int j = u.second;
    //cout << i << j << endl;
    if (i == 0 && j == 0){
      result++;
      while (parent[i*100 + j] != -1){
        result++;
        int ii = parent[i*100 + j]/100;
        int jj = parent[i*100 + j]%100;
        i = ii;
        j = jj;
        //cout << i << j << endl;
      }
      return result;
    }
    for (int a = 0; a < 8; a++){
      int rr = i + dr[a];
      int cc = j + dc[a];
      if (rr >= 0 && rr < n && cc >= 0 && cc < n){
        if (parent.find(rr*100 + cc) == parent.end() && board[rr][cc] != '#'){
          parent[rr*100 + cc] = i*100 + j;
          pq.push({rr, cc});
        }
      }
    }
  }
  return result;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    board.push_back(line);
  }
  int r;
  int c;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (board[i][j] == 'K'){
        r = i;
        c = j;
      }
    }
  }
  cout << bfs(r, c, n);
}
