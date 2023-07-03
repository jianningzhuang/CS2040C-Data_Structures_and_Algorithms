#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  while (n != 0){
    unordered_map<int, int> m;
    unordered_set<string> s;
    for (int i = 0; i < n; i++){
      string line;
      getline(cin, line);
      if (s.find(line) == s.end()){
        s.insert(line);
      }
      int hash = 0;
      for (auto &c : line){
        hash += int(c);
      }
      m[hash]++;
    }
    int collision = 0;
    for (auto i = m.begin(); i != m.end(); i++){
      if (i->second != 1){
        collision += (i->second)*(i->second - 1)/2;
      }
    }
    cout << s.size() << collision << endl;
    cin >> n;
    cin.ignore();
  }
}
