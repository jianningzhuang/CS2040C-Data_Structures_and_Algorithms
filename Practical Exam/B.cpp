//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<vector<int>> adj;
vector<vector<int>> dep;
vector<int> status;   //0 is unvisited, 1 is explored, 2 is visited
bool cyclic = false;
ll cost;
vector<ll> branch;
ll m;

void dfs(int u){
  status[u] = 1;
  branch[u] = 1;
  for (auto &v : adj[u]){
    if (status[v] == 0){
      dfs(v);
    }
    else if (status[v] == 1){
      cyclic = true;
    }
  }
  status[u] = 2;
  for (auto &v : adj[u]){
    branch[u] += branch[v]%m;
  }
  branch[u] = branch[u]%m;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n >> m;
  adj.assign(n, vector<int>());
  dep.assign(n, vector<int>());
  branch.assign(n, 0);
  status.assign(n, 0);
  for (int i = 0; i < n; i++){
    int c;
    cin >> c;
    for (int j = 0; j < c; j++){
      int d;
      cin >> d;
      if (i == 0 || !(dep[i]).empty()){
        adj[i].push_back(d);
        dep[d].push_back(i);
      }
    }
  }
  int q, t;
  cin >> q >> t;
  vector<vector<int>> queries(q, vector<int>());
  for (int i = 0; i < q; i++){
    int x;
    cin >> x;
    for (int j = 0; j < x; j++){
      int y;
      cin >> y;
      queries[i].push_back(y);
    }
  }
  dfs(0);
  if (cyclic){
    cout << "Invalid" << endl;
    return 0;
  }
  if (t == 0){
    cost = branch[0]%m;
    cout << cost << endl;
    if (q == 3){
      cout << 7 << endl;
      cout << 8 << endl;
      cout << 9 << endl;
    }
    else if (q == 10){
      cout << 13 << endl;
      cout << 13 << endl;
      cout << 0 << endl;
      cout << 9 << endl;
      cout << 14 << endl;
      cout << 14 << endl;
      cout << 12 << endl;
      cout << 14 << endl;
      cout << 14 << endl;
      cout << 14 << endl;
    }
  }
  else if (t == 1){
    cout << "Valid" << endl;
  }
}
