#include <bits/stdc++.h>
using namespace std;

int main(){
  string prev;
  cin >> prev;
  int n;
  cin >> n;
  vector<string> all;
  vector<string> pos;
  for (int i = 0; i < n; i++){
    string animal;
    cin >> animal;
    all.push_back(animal);
    if (prev.back() == animal.front()){
      pos.push_back(animal);
    }
  }
  if (pos.empty()){
    cout << "?\n";
  }
  else{
    for (auto it = pos.begin(); it != pos.end(); it++){
      bool final = true;
      for (auto is = all.begin(); is != all.end(); is++){
        if (it->back() == is->front() && *it != *is){
          final = false;
          break;
        }
      }
      if (final){
        cout << *it << "!\n";
        return 0;
      }
    }
    cout << *(pos.begin());
  }
}
