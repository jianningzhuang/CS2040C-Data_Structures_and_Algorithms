#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<pair<int, int>> vii;

const int INF = 1e9;

vector<vii> adj;
vector<ll> dist;

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
      if (t == s){
        cout << 0 << endl;
        continue;
      }
      unordered_map<int, ll> curr;
      set<tuple<int, ll, int>> pq;
      dist.assign(V, INF);
      dist[s] = 0;
      pq.insert({1, dist[s], s});
      while (!pq.empty()){
        tuple<int, ll, int> p = *pq.begin();
        pq.erase(pq.begin());
        ll d = get<1>(p);
        int u = get<2>(p);
        int moves = get<0>(p);
        if (moves < k){
          for (auto &p1 : adj[u]){
            int v = p1.first;
            ll w = p1.second;
            //cout << u << v << w << endl;
            if (dist[v] > d + w){
              curr[v] = d + w;
              pq.insert({moves+1, curr[v], v});
            }
            // else{
            //
            // }
            // if (curr[v] != 0){
            //   if (curr[v] > d + w){
            //     pq.insert({moves+1, curr[v], v});
            //   }
            // }
            // else{
            //   if (dist[v] > d + w){
            //     curr[v] = d + w;
            //     pq.insert({moves+1, curr[v], v});
            //   }
            // }
          }
        }
        for (auto it = curr.begin(); it != curr.end(); it++){
          if (it->second != 0){
            dist[it->first] = it->second;
          }
        }
        curr.clear();
      }
      ll min = dist[t];
      if (min == INF){
        cout << "-1" << endl;
      }
      else{
        cout << min << endl;
      }
    }
    cout << endl;
  }
}
