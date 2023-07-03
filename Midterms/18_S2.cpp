#include <bits/stdc++.h>
using namespace std;

int main(){
  string name;
  vector<string> v;
  while (cin >> name){
    if (name == "Jianning"){
      break;
    }
    v.push_back(name);
  }
  sort(v.begin(), v.end(), [](string a, string b){ //O(mnlogn cos compare no longer O(1))
    while (a.back() == b.back()){
      a.pop_back();
      b.pop_back();
      if (a.empty()){
        return true;
      }
      else if (b.empty()){
        return false;
      }
    }
    return a.back() < b.back();
  });
  for (auto i = v.begin(); i != v.end(); i++){
    cout << *i << endl;
  }
}
