#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adj;
unordered_map<int, bool> visited;

void dfs(int u){
  visited[u] = true;
  for (auto &v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
  }
}


int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    adj.clear();
    visited.clear();
    int m;
    cin >> m;
    int r;
    cin >> r;
    for (int j = 0; j < r; j++){
      int start, end;
      cin >> start >> end;
      adj[start].push_back(end);
      adj[end].push_back(start);
    }
    int cc = 0;
    for (int u = 0; u < m; u++){
      if (!visited[u]){
        cc++;
        dfs(u);
      }
    }
    cout << cc - 1 << endl;
  }
}
