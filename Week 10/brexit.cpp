#include <bits/stdc++.h>
using namespace std;

//start 1033 to


int main(){
  int c, p, x, l;
  cin >> c >> p >> x >> l;
  vector<set<int>> adj(c + 1);
  vector<int> partners(c + 1);
  for (int i = 0; i < p; i++){
    int start, end;
    cin >> start >> end;
    adj[start].insert(end);
    adj[end].insert(start);
  }
  for (int i = 1; i <= c; i++){
    partners[i] = adj[i].size();
  }
  if (l == x){
    cout << "leave\n";
    return 0;
  }
  queue<int> q;
  q.push(l);
  while (!q.empty()){
    int u = q.front();
    q.pop();
    set<int> temp = adj[u];
    for (auto &v : temp){
      if (adj[u].find(v) != adj[u].end()){
        adj[u].erase(v);
      }
      if (adj[v].find(u) != adj[v].end()){
        adj[v].erase(u);
      }
      if (adj[v].size() * 2 <= partners[v]){
        q.push(v);
        if (v == x){
          cout << "leave\n";
          return 0;
        }
      }
    }
  }
  cout << "stay\n";
}
