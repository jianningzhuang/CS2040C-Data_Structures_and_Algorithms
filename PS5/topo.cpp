#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<pair<int, int>> vii;

const ll INF = 1e19;

vector<vii> adj;
vector<ll> dist;
vector<int> status;
vector<int> topological;

void toposort(int u){
  status[u] = 1;
  for (auto &p : adj[u]){
    int v = p.first;
    if (status[v] == 0){
      toposort(v);
    }
  }
  topological.push_back(u);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int V;
    cin >> V;
    adj.assign(V, vii());
    for (int j = 0; j < V; j++){
      int X;
      cin >> X;
      for (int k = 0; k < X; k++){
        int v, w;
        cin >> v >> w;
        adj[j].push_back({v, w});
      }
    }
    int Q;
    cin >> Q;
    for (int j = 0; j < Q; j++){
      int s, t, k;
      cin >> s >> t >> k;
      dist.assign(V, INF);
      dist[s] = 0;
      set<pair<ll, int>> pq;
      pq.clear();
      for (int m = 0; m < V; m++){
        pq.insert({dist[m], m});
      }
      if (k >= V){
        while (!pq.empty()){
          pair<ll, int> p = *pq.begin();
          pq.erase(pq.begin());
          ll d = p.first;
          int u = p.second;
          for (auto &p1 : adj[u]){
            int v = p1.first;
            ll w = p1.second;
            if (dist[v] > dist[u] + w){
              pq.erase(pq.find({dist[v], v}));
              dist[v] = dist[u] + w;
              pq.insert({dist[v], v});
            }
          }
        }
      }
      else{
        status.assign(V, 0);
        topological.clear();
        toposort(s);
        for (int i = 1; i < k; i++){
          if (!topological.empty()){
            int u = topological.back();
            topological.pop_back();
            for (auto &p1 : adj[u]){
              int v = p1.first;
              ll w = p1.second;
              //cout << u << v << w << endl;
              if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
              }
            }
          }
        }
      }
      if (dist[t] == INF){
        cout << "-1" << endl;
      }
      else{
        cout << dist[t] << endl;
      }
    }
    cout << endl;
  }
}
