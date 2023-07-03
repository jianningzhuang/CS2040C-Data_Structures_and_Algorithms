#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  int counter = 0;
  while (n != 0){
    counter++;
    map<string, int> m;
    for (int i = 0; i < n; i++){
      string animal;
      getline(cin, animal);
      string type = "";
      for (auto &c : animal){
        if (c == ' '){
          type = "";
        }
        else{
          type += tolower(c);
        }
      }
      m[type]++;
    }
    cout << "List " << counter << ":\n";
    for (auto it = m.begin(); it != m.end(); it++){
      cout << it->first << " | " << it->second << endl;
    }
    cin >> n;
    cin.ignore();
  }
}
