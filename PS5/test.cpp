#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const ll INF = 1e12;
int V;

ll shortestpath(vector<vector<ll>> AM, int u, int v, int k){
  ll sp[V][V][k+1];
  for (int e = 0; e <= k; e++){
    for (int i = 0; i < V; i++){
      for (int j = 0; j < V; j++){
        sp[i][j][e] = INF;
        if (e == 0 && i == j){
          sp[i][j][e] = 0;
        }
        if (e == 1 && AM[i][j] != INF){
          sp[i][j][e] = AM[i][j];
        }
        if (e > 1){
          for (int a = 0; a < V; a++){
            if (AM[i][a] != INF && i != a && j!= a && sp[a][j][e-1] != INF){
              sp[i][j][e] = min(sp[i][j][e], (AM[i][a] + sp[a][j][e-1]));
            }
          }
        }
      }
    }
  }
  set<ll> s;
  s.insert(INF);
  for (int i = 1; i < k; i++){
    s.insert(sp[u][v][i]);
  }
  return *s.begin();
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    cin >> V;
    vector<vector<ll>> AM;
    AM.assign(V, vector<ll>(V));
    for (int j = 0; j < V; j++){
      for (int l = 0; l < V; l++){
        if (j != l){
          AM[j][l] = INF;
        }
      }
    }
    for (int j = 0; j < V; j++){
      int X;
      cin >> X;
      for (int k = 0; k < X; k++){
        int v;
        ll w;
        cin >> v >> w;
        AM[j][v] = w;
      }
    }
    int Q;
    cin >> Q;
    for (int j = 0; j < Q; j++){
      int s, t, k;
      cin >> s >> t >> k;
      ll min = shortestpath(AM, s, t, k);
      if (min == INF){
        cout << -1 << endl;
      }
      else{
        cout << min << endl;
      }
    }
    cout << endl;
  }
}
