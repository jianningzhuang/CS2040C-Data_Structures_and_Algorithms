#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<pair<int, int>> vii;

const ll INF = 1e18;

vector<vii> adj;
vector<int> clearing;
vector<ll> dist;
vector<int> shortest;
set<pair<ll, int>> pq;


int main(){
  int V, E, C;
  ll K, M;
  cin >> V >> E >> C >> K >> M;
  adj.assign(V + 1, vii());
  for (int i = 0; i < E; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  clearing.assign(V + 1, 0);
  for (int i = 0; i < C; i++){
    int f;
    cin >> f;
    clearing[f] = 1;
  }
  dist.assign(V+1, INF);
  dist[1] = 0;
  for (int i = 1; i <= V; i++){
    pq.insert({dist[i], i});
  }
  while (!pq.empty()){
    pair<ll, int> p = *pq.begin();
    pq.erase(pq.begin());
    ll d = p.first;
    int u = p.second;
    shortest.push_back(u);
    for (auto &p1 : adj[u]){
      int v = p1.first;
      int w = p1.second;
      if (dist[v] > dist[u] + w){
        pq.erase(pq.find({dist[v], v}));
        dist[v] = dist[u] + w;
        pq.insert({dist[v], v});
      }
    }
  }
  for (int i = 0; i < shortest.size(); i++){
    if (clearing[shortest[i]] == 1){
      K--;
      M--;
    }
    if (K == 0 || M == 0){
      if (dist[shortest[i]] != INF){
        cout << dist[shortest[i]]*2 << endl;
      }
      else{
        cout << -1 << endl;
      }
      return 0;
    }
  }
  if (K || M){
    cout << -1 << endl;
  }
}
