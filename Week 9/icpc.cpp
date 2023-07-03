#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_set<string> s;
  for (int i = 0; i < n; i++){
    string uni, team;
    cin >> uni >> team;
    if (s.empty()){
      s.insert(uni);
      cout << uni << " " << team << endl;
    }
    else{
      if (s.find(uni) == s.end() && s.size() < 12){
        s.insert(uni);
        cout << uni << " " << team << endl;
      }
      if (s.size() == 12){
        return 0;
      }
    }
  }
}
