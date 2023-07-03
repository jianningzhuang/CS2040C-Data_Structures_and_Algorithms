#include <bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<string, int> m;
  string cmd;
  while (cin >> cmd){
    if (cmd == "define"){
      int val;
      string word;
      cin >> val >> word;
      m[word] = val;
    }
    else if (cmd == "eval"){
      string x, y, z;
      cin >> x >> y >> z;
      if (m.find(x) == m.end() || m.find(z) == m.end()){
        cout << "undefined\n";
      }
      else{
        if (y == "<"){
          if (m[x] < m[z]){
            cout << "true\n";
          }
          else{
            cout << "false\n";
          }
        }
        else if (y == "="){
          if (m[x] == m[z]){
            cout << "true\n";
          }
          else{
            cout << "false\n";
          }
        }
        else if (y == ">"){
          if (m[x] > m[z]){
            cout << "true\n";
          }
          else{
            cout << "false\n";
          }
        }
      }
    }
  }
}
