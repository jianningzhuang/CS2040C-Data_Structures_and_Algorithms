#include <bits/stdc++.h>
using namespace std;

//start 916 to

vector<string> screen;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    string line;
    cin >> line;
    screen.push_back(line);
  }
  int total = 0;
  for (int j = 0; j < m; j++){
    bool col = true;
    for (int i = 0; i < n; i++){
      if (screen[i][j] == '$'){
        col = false;
        break;
      }
    }
    if (col){
      total++;
    }
  }
  cout << total + 1 << endl;
}
