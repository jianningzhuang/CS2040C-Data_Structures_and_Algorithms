#include <bits/stdc++.h>
using namespace std;

//10:24 to

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int n;
    cin >> n;
    map<int, set<string>> ordered;
    unordered_map<string, int> m;
    for (int j = 0; j < n; j++){
      string name;
      int amount;
      cin >> name >> amount;
      m[name] += amount;
    }
    cout << m.size() << endl;
    for (auto it = m.begin(); it != m.end(); it++){
      ordered[it->second].insert(it->first);
    }
    for (auto it = ordered.rbegin(); it != ordered.rend(); it++){
      set<string> temp = it->second;
      for (auto is = temp.begin(); is != temp.end(); is++){
        cout << *is << " " << it->first << endl;
      }
    }
  }
}
