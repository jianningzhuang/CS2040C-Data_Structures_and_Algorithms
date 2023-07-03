#include <bits/stdc++.h>
using namespace std;

//start 1252 to

vector<string> planet;
vector<pair<int, int>> adj = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int i, int j, int r, int c){
  planet[i][j] = 'W';
  for (auto &p : adj){
    int i1 = i + p.first;
    int j1 = j + p.second;
    if (i1 >= 0 && i1 < r && j1 >= 0 && j1 < c){
      if (planet[i1][j1] == 'C' || planet[i1][j1] == 'L'){
        planet[i1][j1] = 'W';
        dfs(i1, j1, r, c);
      }
    }
  }
}


int main(){
  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++){
    string line;
    cin >> line;
    planet.push_back(line);
  }
  int numcc = 0;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (planet[i][j] == 'L'){
        numcc++;
        dfs(i, j, r, c);
      }
    }
  }
  cout << numcc << endl;
}
