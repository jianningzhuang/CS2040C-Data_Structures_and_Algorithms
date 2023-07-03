#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef vector<pair<int, int>> vii;

vector<vii> adj;
vector<int> dist;
unordered_map<int, int> pred;

int main(){
  int n, m;
  cin >> n >> m;
  adj.assign(n, vii());
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  for (int i = 0; i < n; i++){
    if (i == 7){
      cout << -1 << endl;
      continue;
    }
    dist.assign(n, INF);
    dist[i] = 0;
    pred[i] = -1;
    set<pair<int, int>> pq;
    for (int j = 0; j < n; j++){
      pq.insert({dist[j], j});
    }
    while (!pq.empty()) {
      pair<int, int> p = *pq.begin();
      pq.erase(pq.begin());
      int d = p.first;
      int u = p.second;
      //cout << u << endl;
      if (u == 7){
        break;
      }
      for (auto &p1 : adj[u]) {
        int v = p1.first;
        int w = p1.second;
        if (dist[u]+w >= dist[v]) continue;
        pq.erase(pq.find({dist[v], v}));
        dist[v] = dist[u]+w;
        pred[v] = u;
        pq.insert({dist[v], v});
      }
    }
    int curr = 7;
    while (pred[curr] != i){
      curr = pred[curr];
    }
    cout << curr << endl;
  }
}
