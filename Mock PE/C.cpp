#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<map<int, int>> adj(n + 1);
  vector<int> thr(n + 1);
  vector<int> curr(n+1);
  vector<set<int>> link(n + 1);
  vector<set<int>> rec(n + 1);
  for (int i = 1; i <= n; i++){
    int threshold, k;
    cin >> threshold >> k;
    thr[i] = threshold;
    curr[i] = 0;
    for (int j = 0; j < k; j++){
      int s, v;
      cin >> s >> v;
      adj[s][i] = v;
      curr[i] += v;
      link[s].insert(i);
      rec[i].insert(s);
    }
  }
  queue<int> q;
  set<int> vis;
  q.push(1);
  while (!q.empty()){
    int u = q.front();
    q.pop();
    vis.insert(u);
    set<int> temp = link[u];
    for (auto &v : temp){
      if (link[u].find(v) != link[u].end()){
        link[u].erase(v);
        //curr[v] -= adj[u][v];
      }
      if (rec[v].find(u) != rec[v].end()){
        rec[v].erase(u);
        curr[v] -= adj[u][v];
      }
      if (curr[v] < thr[v]){
        q.push(v);
      }
    }
  }
  cout << n - vis.size() << endl;
}
