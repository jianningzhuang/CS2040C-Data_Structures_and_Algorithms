#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
      cout << parent[u] << endl;
      return 0;
    }
    for (auto &v : adj[u]){
      if (!visited[v]){
        parent[v] = parent[u] + 1;
        visited[v] = 1;
        q.push(v);
      }
    }
  }
}
