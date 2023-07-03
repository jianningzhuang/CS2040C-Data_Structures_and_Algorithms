#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const ll INF = 1e18;

vector<pair<int, int>> shades;
vector<ll> dist;
unordered_map<int, int> parent;

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    ll x, y;
    cin >> x >> y;
    shades.push_back({x, y});
  }
  ll dx, dy, cx, cy;
  cin >> dx >> dy >> cx >> cy;
  pair<ll, ll> s = {dx, dy};
  pair<ll, ll> t = {cx, cy};
  dist.assign(n + 2, INF);
  dist[n+1] = 0; // dorm at index n, class at index n+1
  ll initial = (cx - dx)*(cx - dx) + (cy - dy)*(cy - dy);
  shades.push_back(t);
  shades.push_back(s);
  set<pair<ll, int>> pq;
  for (int i = 0; i < n + 2; i++){
    pq.insert({dist[i], i});
  }
  while (!pq.empty()){
    pair<ll, int> p = *pq.begin();
    pq.erase(pq.begin());
    ll d = p.first;
    int u = p.second;
    for (int j = 0; j <= n; j++){
      ll ux = shades[u].first;
      ll uy = shades[u].second;
      ll vx = shades[j].first;
      ll vy = shades[j].second;
      ll temp = (vx - ux)*(vx - ux) + (vy - uy)*(vy - uy);
      if (temp > 0 && dist[j] > dist[u] + temp){
        pq.erase(pq.find({dist[j], j}));
        dist[j] = dist[u] + temp;
        pq.insert({dist[j], j});
        parent[j] = u;
      }
    }
  }
  if (dist[n] == initial){
    cout << "-\n";
  }
  else{
    stack<int> st;
    int it = n;
    while (parent[it] != n+1){
      st.push(parent[it]);
      it = parent[it];
    }
    while (!st.empty()){
      cout << st.top() << endl;
      st.pop();
    }
  }
}
