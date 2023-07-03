#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while (cin >> n && n != 0){
    cin.ignore();
    map<string, set<string>> m;
    for (int i = 0; i < n; i++){
      string name;
      cin >> name;
      cin.ignore();
      string line;
      getline(cin, line);
      string food = "";
      for (auto &c : line){
        if (c != ' '){
          food += c;
        }
        else{
          m[food].insert(name);
          food = "";
        }
      }
      m[food].insert(name);
    }
    for (auto it = m.begin(); it != m.end(); it++){
      cout << it->first << " ";
      for (auto is = (it->second).begin(); is != (it->second).end(); is++){
        cout << *is << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
