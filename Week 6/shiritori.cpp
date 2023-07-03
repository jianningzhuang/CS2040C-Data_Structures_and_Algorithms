#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_set<string> s;
  string prev = "";
  for (int i = 0; i < n; i++){
    string word;
    cin >> word;
    if (s.find(word) == s.end()){
      s.insert(word);
    }
    else{
      int loser = 0;
      if ((i+1)%2 == 1){
        loser = 1;
      }
      else{
        loser = 2;
      }
      cout << "Player " << loser << " lost\n";
      return 0;
    }
    if (prev == ""){
      prev = word;
    }
    else{
      if (prev.back() != word.front()){
        int loser = 0;
        if ((i+1)%2 == 1){
          loser = 1;
        }
        else{
          loser = 2;
        }
        cout << "Player " << loser << " lost\n";
        return 0;
      }
    }
    prev = word;
  }
  cout << "Fair Game\n";
}
