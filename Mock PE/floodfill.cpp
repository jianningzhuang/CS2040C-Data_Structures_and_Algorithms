#include <bits/stdc++.h>
using namespace std;

//start 9:41 to

int main(){
  int n;
  cin >> n;
  vector<int> threshold(n+1);
  vector<int> current(n+1);
  vector<vector<pair<int, int>>> adj(n+1);
  for (int i = 1; i <= n; i++){
    int t, k;
    cin >> t >> k;
    threshold[i] = t;
    for (int j = 0; j < k; j++){
      int s, v;
      cin >> s >> v;
      current[i] += v;
      adj[s].push_back({i, v});
    }
  }
  queue<int> q;
  vector<int> collapsed(n+1);
  q.push(1);
  collapsed[1] = 1;
  while (!q.empty()){
    int u = q.front();
    q.pop();
    for (auto &p : adj[u]){
      int v = p.first;
      int w = p.second;
      current[v] -= w;
      if (current[v] < threshold[v]){
        if (!collapsed[v]){
          collapsed[v] = 1;
          q.push(v);
        }
      }
    }
  }
  int num = 0;
  for (int i = 1; i <= n; i++){
    if (collapsed[i] == 1){
      num++;
    }
  }
  cout << n - num << endl;
}
