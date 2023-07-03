#include <bits/stdc++.h>
using namespace std;

//start 10:21 to

vector<vector<int>> adj;
vector<int> visited;
int numcc = 0;
int colour = 1;
bool bip = true;

void dfs(int u){
  visited[u] = colour;
  cout << u << colour << endl;
  for (auto &v : adj[u]){
    for (auto &w : adj[v]){
      if (!visited[w]){
        colour *= -1;
        dfs(w);
      }
      else if (u != w && visited[w] == visited[u]){
        bip = false;
      }
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  adj.assign(n+1, vector<int>());
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  visited.assign(n+1, 0);
  for (int i = 1; i <= n; i++){
    if (!visited[i]){
      colour = 1;
      numcc++;
      dfs(i);
    }
  }
  if (numcc == 1){
    cout << 0 << endl;
  }
  else if (bip){
    cout << numcc - 1 << "yep" << endl;
  }
  else{
    cout << numcc << endl;
  }
}
