#include <bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<string, vector<string>> adj;
  unordered_map<string, int> level;
  unordered_map<string, string> parent;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string start, end;
    cin >> start >> end;
    adj[start].push_back(end);
    adj[end].push_back(start);
  }
  string s;
  cin >> s;
  queue<string> q;
  q.push(s);
  level[s] = 0;
  parent[s] = "-1";
  while (!q.empty()){
    string u = q.front();
    q.pop();
    for (auto &v : adj[u]){
      if (level.find(v) == level.end()){
        level[v] = level[u] + 1;
        parent[v] = u;
        q.push(v);
      }
    }
  }
  for (auto it = level.begin(); it != level.end(); it++){
    cout << it->first << " at level " << it->second << endl;
  }

}
