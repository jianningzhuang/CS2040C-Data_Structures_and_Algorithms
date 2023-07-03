#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>> adj, vector<int> visited){
  visited[start] = 1;
  for (auto &v : adj[start]){
    if (!visited[v]){
      dfs(v, adj, visited);
    }
  }
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int m;
    cin >> m;
    int r;
    cin >> r;
    vector<vector<int>> adj(m);
    for (int j = 0; j < r; j++){
      int start, end;
      cin >> start >> end;
      adj[start].push_back(end);
      adj[end].push_back(start);
    }
    int numCC = 0;
    vector<int> visited(m);
    for (int k = 0; k < m; k++){
      if (!visited[k]){
        numCC++;
        dfs(k, adj, visited);
      }
    }
    cout << numCC - 1 << endl;
  }
}
