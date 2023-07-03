#include <bits/stdc++.h>
using namespace std;

//start 8:25 to

vector<int> stages;
vector<vector<int>> adj;
vector<int> degree;
int n, m;

int process(vector<vector<int>> adj1, vector<int> degree1, bool one){
  queue<int> pq1;
  queue<int> pq2;
  for (int j = 1; j <= n; j++){
    if (degree1[j] == 0){
      if (stages[j] == 1){
        pq1.push(j);
      }
      else{
        pq2.push(j);
      }
    }
  }
  int transfer = -1;
  while (!pq1.empty() || !pq2.empty()){
    transfer++;
    if (one){
      while (!pq1.empty()){
        int u = pq1.front();
        pq1.pop();
        //cout << u << transfer << endl;
        for (auto &v : adj1[u]){
          degree1[v]--;
          if (degree1[v] == 0){
            if (stages[v] == 1){
              pq1.push(v);
            }
            else{
              pq2.push(v);
            }
          }
        }
      }
      one = false;
    }
    else{
      while (!pq2.empty()){
        int u = pq2.front();
        pq2.pop();
        //cout << u << transfer << endl;
        for (auto &v : adj1[u]){
          degree1[v]--;
          if (degree1[v] == 0){
            if (stages[v] == 1){
              pq1.push(v);
            }
            else{
              pq2.push(v);
            }
          }
        }
      }
      one = true;
    }
  }
  return transfer;
}

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    cin >> n >> m;
    stages.assign(n+1, 0);
    for (int j = 1; j <= n; j++){
      int stage;
      cin >> stage;
      stages[j] = stage;
    }
    adj.assign(n+1, vector<int>());
    degree.assign(n+1, 0);
    for (int j = 0; j < m; j++){
      int start, end;
      cin >> start >> end;
      adj[start].push_back(end);
      degree[end]++;
    }
    cout << min(process(adj, degree, true), process(adj, degree, false)) << endl;
  }
}
