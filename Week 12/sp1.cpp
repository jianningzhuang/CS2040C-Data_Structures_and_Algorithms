#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const ll INF = 1e18;

vector<vector<pair<int, int>>> adj;
vector<ll> dist;

int main(){
  int n, m, q, s;
  while (cin >> n >> m >> q >> s, (n || m || q || s)){
    adj.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++){
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
    }
    dist.assign(n, INF);
    dist[s] = 0;
    set<pair<ll, int>> pq;
    for (int i = 0; i < n; i++){
      pq.insert({dist[i], i});
    }
    while (!pq.empty()){
      pair<int, int> p = *pq.begin();
      pq.erase(pq.begin());
      ll d = p.first;

      int uu = p.second;
      for (auto &p1 : adj[uu]){
        int vv = p1.first;
        ll ww = p1.second;
        if (dist[vv] > dist[uu] + ww){
          pq.erase(pq.find({dist[vv], vv}));
          dist[vv] = dist[uu] + ww;
          pq.insert({dist[vv], vv});
        }
      }
    }
    for (int i = 0; i < q; i++){
      int t;
      cin >> t;
      if (t >= n || dist[t] == INF){
        cout << "Impossible\n";
      }
      else{
        cout << dist[t] << endl;
      }
    }
    cout << endl;
  }
}
