#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> seq;
  set<int> s;
  for (int i = 0; i < m; i++){
    int g;
    cin >> g;
    seq.push_back(g);
    s.insert(g);
  }
  set<int> missing;
  for (int i = 1; i <= n; i++){
    if (s.find(i) == s.end()){
      missing.insert(i);
    }
  }
  auto it = seq.begin();
  auto is = missing.begin();
  while (it != seq.end() && is != missing.end()){
    if (*it < *is){
      cout << *it << endl;
      it++;
    }
    else{
      cout << *is << endl;
      is++;
    }
  }
  while (it != seq.end()){
    cout << *it << endl;
    it++;
  }
  while (is != missing.end()){
    cout << *is << endl;
    is++;
  }

}
