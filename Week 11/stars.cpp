#include <bits/stdc++.h>
using namespace std;

//start 6:32 to

vector<string> sky;
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, 1, -1};
int casenum = 0;

void dfs(int r, int c, int m, int n){
  sky[r][c] = '#';
  for (int i = 0; i < 4; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 0 && rr < m && cc >= 0 && cc < n){
      if (sky[rr][cc] == '-'){
        dfs(rr, cc, m, n);
      }
    }
  }
}

int main(){
  int m, n;
  while (cin >> m){
    casenum++;
    cin >> n;
    sky.clear();
    for (int i = 0; i < m; i++){
      string line;
      cin >> line;
      sky.push_back(line);
    }
    int numcc = 0;
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if (sky[i][j] == '-'){
          numcc++;
          dfs(i, j, m, n);
        }
      }
    }
    cout << "Case " << casenum << ": " << numcc << endl;
  }
}
