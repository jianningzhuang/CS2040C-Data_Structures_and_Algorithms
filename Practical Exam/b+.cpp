//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<unordered_map<int, int>> adj;
vector<int> status;
vector<ll> costs;
vector<ll> updates;
bool cyclic = false;
ll m;

void dfs(int u){
  status[u] = 1;
  for (auto &v : adj[u]){
    if (status[v.first] == 0){
      dfs(v.first);
    }
    else if (status[v.first] == 1){
      cyclic = true;
    }
  }
  status[u] = 2;
}

ll buildcost(int u){
  if (costs[u] != -1){
    return costs[u];
  }
  ll total = 1;
  for (auto &v: adj[u]){
    total += v.second * buildcost(v.first);
  }
  costs[u] = total%m;
  return total%m;
}

pair<ll, int> updatecost(int u, unordered_set<int> &targets){
  if (builds[u] != -1){
    return {builds[u], }
  }
  if (targets.find(u) != targets.end()){
    return {costs[u], 1};
  }
  ll total = 0;
  bool valid = false;
  for (auto &v : adj[u]){
    auto result = updatecost(v.first, targets);
    if (result.second){
      valid = true;
      total += (total + v.second * result.first)%m;
    }
  }
  if (!valid){
    return {0, 0};
  }
  total = (total+1)%m;
  return {total, 1};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n >> m;
  adj.assign(n, unordered_map<int, int>());
  status.assign(n, 0);
  costs.assign(n, -1);
  for (int i = 0; i < n; i++){
    int c;
    cin >> c;
    for (int j = 0; j < c; j++){
      int d;
      cin >> d;
      if (adj[i].find(d) == adj[i].end()){
        adj[i][d] = 1;
      }
      else{
        adj[i][d]++;
      }
    }
  }
  int q, t;
  cin >> q >> t;
  dfs(0);
  if (cyclic){
    cout << "Invalid" << endl;
    return 0;
  }
  if (t == 0){
    cout << buildcost(0)%m << endl;
  }
  else if (t == 1){
    cout << "Valid" << endl;
    return 0;
  }
  for (int i = 0; i < q; i++){
    int x;
    cin >> x;
    unordered_set<int> targets;
    for (int j = 0; j < x; j++){
      int y;
      cin >> y;
      targets.insert(y);
    }
    cout << updatecost(0, targets).first << endl;
  }
  return 0;
}
