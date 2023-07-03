#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int n;
    cin >> n;
    map<string, set<string>> pizza;
    for (int j = 0; j < n; j++){
      string name;
      cin >> name;
      int m1;
      cin >> m1;
      set<string> curr;
      for (int k = 0; k < m1; k++){
        string ingre;
        cin >> ingre;
        curr.insert(ingre);
      }
      int m2;
      cin >> m2;
      for (int k = 0; k < m2; k++){
        string ingre;
        cin >> ingre;
        set<string> temp;
        for (auto it = curr.begin(); it != curr.end(); it++){
          if (pizza[*it].find(ingre) )
        }
      }
    }
    for (auto it = pizza.begin(); it != pizza.end(); it++){
      for (auto is = (it->second).begin(); is != (it->second).end(); is++){
        cout << it->first << " " << *is << endl;
      }
    }
  }
}
