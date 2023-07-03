#include <bits/stdc++.h>
using namespace std;

//start 11:08

typedef vector<int> vi;

vector<vi> garden;
vector<vi> visited;

int numcc;
int total = 0;
bool pool;
vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

void dfs(int r, int c, int x, int y){
  numcc++;
  visited[r][c] = 1;
  for (int i = 0; i < 4; i++){
    int rr = r + dr[i];
    int cc = c + dc[i];
    if (rr >= 0 && rr < y && cc >= 0 && cc < x){
      if (garden[rr][cc] == garden[r][c] && !visited[rr][cc]){
        //cout << rr << cc << endl;
        dfs(rr, cc, x, y);
      }
      else if (garden[rr][cc] < garden[r][c]){
        pool = false;
        continue;
      }
      else{
        continue;
      }
    }
  }


}

int main(){
  int x, y;
  cin >> x >> y;
  garden.assign(y, vi());
  visited.assign(y, vi());
  for (int i = 0; i < y; i++){
    for (int j = 0; j < x; j++){
      int h;
      cin >> h;
      garden[i].push_back(h);
      visited[i].push_back(0);
    }
  }
  for (int i = 0; i < y; i++){
    for (int j = 0; j < x; j++){
      if (visited[i][j] == 0){
        numcc = 0;
        pool = true;
        dfs(i, j, x, y);
        if (pool){
          total += numcc;
          //cout << garden[i][j] << endl;
        }
      }
    }
  }
  cout << total << endl;
}
