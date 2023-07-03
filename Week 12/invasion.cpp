#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vii;
const int INF = 1e9;

vector<vii> adj;
vector<int> dist;
unordered_set<int> unsafe;

int main(){
  int n, m, e, k;
  cin >> n >> m >> e >> k;
  adj.assign(n+1, vii());
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for (int i = 0; i < e; i++){
    int s;
    cin >> s;
    dist.assign(n + 1, INF);
    dist[s] = 0;
    set<pair<int, int>> pq;
    for (int j = 1; j <= n; j++){
      pq.insert({dist[j], j});
    }
    while (!pq.empty()) {
      pair<int, int> p = *pq.begin();
      pq.erase(pq.begin());
      int d = p.first;
      int u = p.second;
      if (dist[u] < k){
        unsafe.insert(u);
      }
      for (auto &p1 : adj[u]) {
        int v = p1.first;
        int w = p1.second;
        if (dist[u]+w >= dist[v]) continue;
        pq.erase(pq.find({dist[v], v}));
        dist[v] = dist[u]+w;
        pq.insert({dist[v], v});
      }
    }
    cout << n - unsafe.size() << endl;
  }
}
