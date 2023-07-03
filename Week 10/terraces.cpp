#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj
vi visited;
vector<vi> cc;

int main(){
  int x, y;
  cin >> x >> y;
  vector<vector<int> garden(y);
  for (int i = 0; i < y; i++){
    for (int j = 0; j < x; j++){
      int grid;
      cin >> grid;
      garden[i].push_back(grid);
    }
  }
  adj.assign(x*y, vi());
  visited.assign(x*y, 0);
}
