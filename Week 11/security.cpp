#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int, int>>> adj;
vector<vector<int>> pospaths;
vector<vector<pair<int, int>>> locks;

int main(){
  int N, L, B;
  cin >> N >> L >> B;
  int S, D;
  cin >> S >> D;
  adj.assign(N+1, vector<tuple<int, int, int>>());
  locks.assign(N+1, vector<pair<int, int>>());
  for (int i = 0; i <= N; i++){
    for (int j = 0; j <= N; j++){
      locks[i].push_back({0, 0});
    }
  }
  for (int i = 0; i < L; i++){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    adj[a].push_back({b, x, y});
    locks[a][b] = {x, y};
  }
  vector<int> initial = {S};
  queue<vector<int>> pq;
  pq.push(initial);
  while (!pq.empty()){
    vector<int> temp = pq.front();
    pq.pop();
    int u = temp.back();
    if (u == D){
      pospaths.push_back(temp);
    }
    else{
      for (auto &t : adj[u]){
        int v = get<0>(t);
        bool flag = true;
        for (int j = 0; j < temp.size(); j++){
          if (temp[j] == v){
            flag = false;
          }
        }
        if (flag){
          vector<int> newp = temp;
          newp.push_back(v);
          pq.push(newp);
        }
      }
    }
  }
  int result = 0;
  vector<pair<int, int> keys;
  for (int i = 0; i < pospaths.size(); i++){
    int start = locks[pospaths[i][0]][pospaths[i][1]].first;
    int end = locks[pospaths[i][0]][pospaths[i][1]].second;
    for (int j = 1; j < pospaths[i].size() - 1; j++){
      int start1 = locks[pospaths[i][j]][pospaths[i][j+1]].first;
      int end1 = locks[pospaths[i][j]][pospaths[i][j+1]].second;
      if (start1 > start){
        start = start1;
      }
      if (end1 < end){
        end = end1;
      }
    }
    for (int k = start; k <= end; k++){
      keys.insert(k);
    }
  }
  cout << keys.size() << endl;
}
