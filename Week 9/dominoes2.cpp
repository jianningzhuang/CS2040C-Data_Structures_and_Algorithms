#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vi visited;
int topple = 0;

void dfs(int u){
  topple++;
  visited[u] = 1;
  for (auto &v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
  }
}

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int n, m, l;
    cin >> n >> m >> l;
    visited.assign(n+1, 0);
    adj.assign(n+1, vi());
    for (int j = 0; j < m; j++){
      int start, end;
      cin >> start >> end;
      adj[start].push_back(end);
    }
    topple = 0;
    for (int j = 0; j < l; j++){
      int u;
      cin >> u;
      if (!visited[u]){
        dfs(u);
      }
    }
    cout << topple << endl;
  }
}
