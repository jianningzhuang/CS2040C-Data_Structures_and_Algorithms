vector<int> dr = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int> dc = {1, 0, -1, 1, -1, 1, 0, -1};

void dfs(int r, int c, int n, int m){
  screen[r][c] = '_';
  for (int i = 0; i < 8; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 0 && rr < n && cc >= 0 && cc < m){
      if (screen[rr][cc] == '$'){
        dfs(rr, cc, n, m);
      }
    }
  }
}

vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

void dfs(int r, int c){
  board[r][c] = '2';
  numcc.push_back({r, c});
  for (int i = 0; i < 4; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 0 && rr < n && cc >= 0 && cc < m && board[rr][cc] == '0'){
      if (rr == 0 || rr == n-1 || cc == 0 || cc == m-1){
        sea = true;
      }
      dfs(rr, cc);
    }
  }
}
