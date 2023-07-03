#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  cin.ignore();
  for (int i = 0; i < tc; i++){
    unordered_set<string> sounds;
    vector<string> ordered;
    string line;
    getline(cin, line);
    stringstream check1(line);
    string temp;
    while (getline(check1, temp, ' ')){
      sounds.insert(temp);
      ordered.push_back(temp);
    }
    string animals;
    while (getline(cin, animals) && animals != "what does the fox say?"){
      stringstream check2(animals);
      string temp2;
      bool fox = false;
      while (getline(check2, temp2, ' ')){
        if (temp2 == "goes" && !fox){
          fox = true;
        }
        else if (fox){
          if (sounds.find(temp2) != sounds.end()){
            sounds.erase(temp2);
          }
        }
      }
    }
    for (auto it = ordered.begin(); it != ordered.end(); it++){
      if (sounds.find(*it) != sounds.end()){
        cout << *it << " ";
      }
    }
  }
}
