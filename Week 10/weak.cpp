#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  while (cin >> n && n != -1){
    if (n < 3){
      for (int i = 0; i < n; i++){
        cout << i << " ";
      }
      cout << endl;
      continue;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        int grid;
        cin >> grid;
        adj[i].push_back(grid);
      }
    }
    for (int i = 0; i < n; i++){
      bool strong = false;
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          if (adj[i][j] == 1 && adj[i][k] == 1 && adj[j][k] == 1 && i!=j && i!= k && j!=k){
            strong = true;
            break;
          }
        }
      }
      if (!strong){
        cout << i << " ";
      }
    }
    cout << endl;
  }
}
