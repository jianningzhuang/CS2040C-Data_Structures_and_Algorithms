#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
unordered_map<int, int> level;
unordered_map<int, int> parent;

void bfs(int s){
  level[s] = 0;
  parent[s] = -1;
  int l = 1;
  vector<int> frontier;
  frontier.push_back(s);
  while (!frontier.empty()){
    vector<int> next;
    for (auto &u : frontier){
      cout << u << endl;
      for (auto &v : adj[u]){
        if (level.find(v) == level.end()){
          level[v] = l;
          parent[v] = u;
          next.push_back(v);
        }
      }
    }
    frontier = next;
    l++;
  }
}

void path(int t){
  if (t == -1){
    return;
  }
  path(parent[t]);
  cout << t << " -> ";
}

void printlevels(){
  for (auto it = level.begin(); it != level.end(); it++){
    cout << it->first << " is at level " << it->second << endl;
  }
}

int main(){
  int n;
  cin >> n;
  adj.assign(n, vi());
  for (int i = 0; i < n; i++){  //number of vertices
    int k;
    cin >> k;
    for (int j = 0; j < k; j++){ //number of neighbours
      int end;
      cin >> end;
      adj[i].push_back(end);
      adj[end].push_back(i);
    }
  }
  bfs(0);
  path(7);
  printlevels();
}
