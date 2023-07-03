#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, e;
  cin >> n >> e;
  vector<unordered_set<int>> v(n + 1);
  int song = 0;
  for (int i = 0; i < e; i++){
    int k;
    cin >> k;
    bool bard = false;
    vector<int> present;
    for (int j = 0; j < k; j++){
      int villager;
      cin >> villager;
      if (villager == 1){
        song++;
        bard = true;
      }
      present.push_back(villager);
    }
    if (bard){
      for (int j = 0; j < present.size(); j++){
        v[present[j]].insert(song);
      }
    }
    else{
      for (int j = 0; j < present.size(); j++){
        for (auto it = v[present[j]].begin(); it != v[present[j]].end(); it++){
          for (int l = 0; l < present.size(); l++){
            v[present[l]].insert(*it);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++){
    if (v[i].size() == song){
      cout << i << endl;
    }
  }
}
