#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vi visited;
vi debt;
vector<vi> cc;

int ccnum = 0;

void dfs(int u){
  visited[u] = 1;
  cc[ccnum].push_back(u);
  for (auto &v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
  }
}

void printcc(){
  for (int i = 0; i < cc.size(); i++){
    for (int j = 0; j < cc[i].size(); j++){
      cout << cc[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  adj.assign(n, vi());
  visited.assign(n, 0);
  debt.assign(n, 0);
  cc.assign(n, vi());
  for (int i = 0; i < n; i++){
    int mon;
    cin >> mon;
    debt[i] = mon;
  }
  for (int i = 0; i < m; i++){
    int start, end;
    cin >> start >> end;
    adj[start].push_back(end);
    adj[end].push_back(start);
  }
  for (int i = 0; i < n; i++){
    if (!visited[i]){
      dfs(i);
      ccnum++;
    }
  }
  //printcc();
  for (int i = 0; i < cc.size(); i++){
    int sum = 0;
    for (int j = 0; j < cc[i].size(); j++){
      sum += debt[cc[i][j]];
    }
    if (sum != 0){
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  cout << "POSSIBLE";
}
