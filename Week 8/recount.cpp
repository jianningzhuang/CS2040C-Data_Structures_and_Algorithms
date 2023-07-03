#include <bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<string, int> m;
  string line;
  while (getline(cin, line) && line != "***"){
    m[line]++;
  }
  int largest = 0;
  for (auto it = m.begin(); it != m.end(); it++){
    if (it->second > largest){
      largest = it->second;
    }
  }
  string winner = "";
  for (auto it = m.begin(); it != m.end(); it++){
    if (it->second == largest){
      if (winner != ""){
        cout << "Runoff!";
        return 0;
      }
      else{
        winner = it->first;
      }
    }
  }
  cout << winner << endl;
}
