#include <bits/stdc++.h>
using namespace std;

//start 1115 to

unordered_map<string, set<string>> adj;
unordered_map<string, int> visited;
vector<string> topo;

void dfs(string u){
  visited[u] = 1;
  for (auto &v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
  }
  topo.push_back(u);
}

int main(){
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++){
    string line;
    getline(cin, line);
    stringstream check1(line);
    string temp;
    string depends;
    while (getline(check1, temp, ' ')){
      if (temp.back() == ':'){
        temp.pop_back();
        depends = temp;
        visited[depends] = 0;
      }
      else{
        adj[temp].insert(depends);
      }
    }
  }
  string start;
  cin >> start;
  dfs(start);
  for (auto it = topo.rbegin(); it != topo.rend(); it++){
    cout << *it << endl;
  }
}
