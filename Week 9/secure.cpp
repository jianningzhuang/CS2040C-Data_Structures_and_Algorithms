#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_set<string> in;
  unordered_set<string> out;
  for (int i = 0; i < n; i++){
    string action, name;
    cin >> action >> name;
    if (action == "entry"){
      if (in.find(name) != in.end()){
        cout << name << " entered (ANOMALY)\n";
      }
      else{
        if (out.find(name) != out.end()){
          out.erase(name);
        }
        in.insert(name);
        cout << name << " entered\n";
      }
    }
    else if (action == "exit"){
      if (out.find(name) != out.end() || in.find(name) == in.end()){
        cout << name << " exited (ANOMALY)\n";
      }
      else{
        if (in.find(name) != in.end()){
          in.erase(name);
        }
        out.insert(name);
        cout << name << " exited\n";
      }
    }
  }
}
