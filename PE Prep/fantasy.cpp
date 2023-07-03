#include <bits/stdc++.h>
using namespace std;

//6:55 to 7:03

int main(){
  int n, k;
  cin >> n >> k;
  vector<set<pair<int, string>>> owners(n);
  vector<unordered_map<string, int>> indiv(n);
  for (int i = 0; i < n; i++){
    int q;
    cin >> q;
    set<pair<int, string>> s;
    for (int j = 0; j < q; j++){
      string name;
      cin >> name;
      s.insert({j, name});
      indiv[i][name] = j;
    }
    owners[i] = s;
  }
  int p;
  cin >> p;
  unordered_map<string, int> m;
  set<pair<int, string>> ranking;
  for (int i = 0; i < p; i++){
    string name;
    cin >> name;
    m[name] = i;
    ranking.insert({i, name});
  }
  vector<vector<string>> teams(n);
  for (int i = 0; i < k; i++){
    for (int j = 0; j < n; j++){
      if (!owners[j].empty()){
        string chosen = owners[j].begin()->second;
        int temp = owners[j].begin()->first;
        ranking.erase({m[chosen], chosen});
        teams[j].push_back(chosen);
        for (int k = 0; k < n; k++){
          if (!owners[k].empty()){
            owners[k].erase({indiv[k][chosen], chosen});
          }
        }
      }
      else{
        string chosen = ranking.begin()->second;
        ranking.erase({m[chosen], chosen});
        teams[j].push_back(chosen);
        for (int k = 0; k < n; k++){
          if (!owners[k].empty()){
            owners[k].erase({indiv[k][chosen], chosen});
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < k; j++){
      cout << teams[i][j] << " ";
    }
    cout << endl;
  }
}
