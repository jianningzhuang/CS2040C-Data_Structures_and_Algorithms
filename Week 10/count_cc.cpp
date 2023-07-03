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
  adj.assign(n, vi());
  visited.assign(n, 0);
  for (int i = 0; i < n; i++){  //number of vertices
    int k;
    cin >> k;
    for (int j = 0; j < k; j++){ //number of neighbours
      int end;
      cin >> end;
      adj[i].push_back(end);
    }
  }
  int numCC = 0;
  for (int i = 0; i < n; i++){
    if (!visited[i]){
      numCC++;
      dfs(i);
    }
  }
  cout << numCC << endl;
}
