#include <bits/stdc++.h>
using namespace std;

//9:51 to

unordered_map<string, vector<string>> adj;
unordered_map<string, int> status;
bool cyclic = false;

void dfs(string u){
  status[u] = 1;
  for (auto &v : adj[u]){
    if (status[v] == 0){
      dfs(v);
    }
    else if (status[v] == 1){
      cyclic = true;
    }
  }
  status[u] = 2;
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string start, end;
    cin >> start >> end;
    if (adj.find(start) == adj.end()){
      adj[start] = {end};
    }
    else{
      adj[start].push_back(end);
    }
    if (status.find(start) == status.end()){
      status[start] = 0;
    }
    if (status.find(end) == status.end()){
      status[end] = 0;
    }
  }
  string city;
  while (cin >> city){
    cyclic = false;
    for (auto it = status.begin(); it != status.end(); it++){
      it->second = 0;
    }
    dfs(city);
    if (cyclic){
      cout << city << " safe\n";
    }
    else{
      cout << city << " trapped\n";
    }
  }
}
