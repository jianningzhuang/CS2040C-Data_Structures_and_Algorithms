#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<pair<int, int>> vii;

const ll INF = 1e18;

vector<vii> adj;
vector<ll> dist;
vector<int> visited;

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
      set<pair<ll, int>> pq;
      dist.assign(V, INF);
      dist[s] = 0;
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
        queue<unordered_set<int>> q;
        q.push({s});
        visited.assign(V, 0);
        for (int l = 0; l < k - 1; l++){
          if (!q.empty()){
            unordered_set<int> frontier = q.front();
            q.pop();
            unordered_set<int> next1;
            unordered_map<int, ll> curr;
            for (auto &u : frontier){
              ll d = dist[u];
              for (auto &p1 : adj[u]){
                int v = p1.first;
                ll w = p1.second;
                if (curr[v] != 0){
                  if (curr[v] > d + w){
                    curr[v] = d + w;
                  }
                }
                else{
                  if (dist[v] > d + w){
                    curr[v] = d + w;
                  }
                }
                if (!visited[v]){
                  next1.insert(v);
                }
              }
            }
            for (auto it = frontier.begin(); it != frontier.end(); it++){
              visited[*it] = 1;
            }
            for (auto it = curr.begin(); it != curr.end(); it++){
              if (it->second != 0){
                dist[it->first] = it->second;
              }
            }
            curr.clear();
            if (!next1.empty()){
              q.push(next1);
            }
            next1.clear();
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
