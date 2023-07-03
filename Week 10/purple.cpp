#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> visited(n+1);
  unordered_map<int, int> parent;
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  parent[1] = -1;
  visited[1] = 1;
  while (!q.empty()){
    int u = q.front();
    q.pop();
    if (u == n){
      int len = 0;
      while (parent[u] != -1){
        len++;
        u = parent[u];
      }
      cout << len - 1 << endl;
      return 0;
    }
    for (auto &v : adj[u]){
      if (!visited[v]){
        parent[v] = u;
        visited[v] = 1;
        q.push(v);
      }
    }
  }
}
