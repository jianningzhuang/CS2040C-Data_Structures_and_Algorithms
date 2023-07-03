#include <bits/stdc++.h>
using namespace std;

//start 1152 to

typedef vector<int> vi;

vector<vi> adj;
vi status;
vi topo;
bool cyclic = false;
unordered_set<int> notroot;

void dfs(int u){
  status[u] = 1;
  for (auto &v : adj[u]){
    if (status[v] == 0){
      dfs(v);
    }
    else if (status[v] == 1){
      cyclic = true;

    }
  }
  status[u] = 2;
  topo.push_back(u);
}

int main(){
  int n, m;
  cin >> n >> m;
  adj.assign(n+1, vi());
  for (int i = 0; i < m; i++){
    int start, end;
    cin >> start >> end;
    adj[start].push_back(end);
    notroot.insert(end);
  }
  for (int i = 1; i <= n; i++){
    if (notroot.find(i) == notroot.end()){
      status.assign(n+1, 0);
      topo.clear();
      dfs(i);
      if (cyclic){
        cout << "IMPOSSIBLE\n";
        return 0;
      }
      else if (topo.size() == n){
        for (auto it = topo.rbegin(); it != topo.rend(); it++){
          cout << *it << endl;
        }
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
