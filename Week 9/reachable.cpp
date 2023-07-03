#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vi visited;

void dfs(int u){
  visited[u] = 1;
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
    int m;
    cin >> m;
    int r;
    cin >> r;
    adj.assign(m, vi());
    visited.assign(m, 0);
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
