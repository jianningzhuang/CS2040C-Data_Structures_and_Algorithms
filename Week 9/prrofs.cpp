#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  unordered_set<string> conclu;
  for (int i = 0; i < n; i++){
    string line;
    getline(cin, line);
    stringstream check1(line);
    string temp;
    bool c = false;
    while (getline(check1, temp, ' ')){
      if (!c && temp != "->"){
        if (conclu.find(temp) == conclu.end()){
          cout << i+1 << endl;
          return 0;
        }
      }
      else if (temp == "->"){
        c = true;
      }
      else{
        conclu.insert(temp);
      }
    }
  }
  cout << "correct\n";
}
