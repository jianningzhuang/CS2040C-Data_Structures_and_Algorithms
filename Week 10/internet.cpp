#include <bits/stdc++.h>
using namespace std;

//start 10:15 to

typedef vector<int> vi;

vector<vi> adj;
vi visited;
unordered_set<int> cc;

void dfs(int u){
  visited[u] = 1;
  cc.insert(u);
  for (auto &v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  adj.assign(n + 1, vi());
  visited.assign(n + 1, 0);
  for (int i = 0; i < m; i++){
    int start, end;
    cin >> start >> end;
    adj[start].push_back(end);
    adj[end].push_back(start);
  }
  dfs(1);
  if (cc.size() == n){
    cout << "Connected\n";
    return 0;
  }
  for (int i = 1; i <= n; i++){
    if (cc.find(i) == cc.end()){
      cout << i << endl;
    }
  }
}
