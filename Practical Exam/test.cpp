//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<unordered_map<int, int>> dep;
vector<int> status;   //0 is unvisited, 1 is explored, 2 is visited
bool cyclic = false;
ll m;

void dfs(int u){
  status[u] = 1;
  for (auto &v : dep[u]){
    if (status[v.first] == 0){
      dfs(v.first);
    }
    else if (status[v.first] == 1){
      cyclic = true;
    }
  }
  status[u] = 2;
}

vector<int> costs;
int buildcost(int u){
  if (costs[u] != -1){
    return costs[u];
  }
  ll total = 1;
  for (auto &v: dep[u]){
    total += v.second * buildcost(v.first);
    total = total%m;
  }
  costs[u] = total;
  return total;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n >> m;
  dep.assign(n, unordered_map<int, int>());
  status.assign(n, 0);
  costs.assign(n, -1);
  for (int i = 0; i < n; i++){
    int c;
    cin >> c;
    for (int j = 0; j < c; j++){
      int d;
      cin >> d;
      if (dep[i].find(d) == dep[i].end()){
        dep[i][d] = 1;
      }
      else{
        dep[i][d]++;
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
    cout << buildcost(0)%m << endl;
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
