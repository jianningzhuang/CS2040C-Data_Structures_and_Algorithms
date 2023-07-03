#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_map<string, int> m;
  for (int i = 0; i < n; i++){
    string cos;
    cin >> cos;
    m[cos]++;
  }
  int lowest = 1001;
  for (auto it = m.begin(); it != m.end(); it++){
    if (it->second < lowest){
      lowest = it->second;
    }
  }
  set<string> s;
  for (auto it = m.begin(); it != m.end(); it++){
    if (it->second == lowest){
      s.insert(it->first);
    }
  }
  for (auto it = s.begin(); it != s.end(); it++){
    cout << *it << endl;
  }
}
