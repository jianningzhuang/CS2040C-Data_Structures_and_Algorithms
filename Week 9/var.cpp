#include <bits/stdc++.h>
using namespace std;

int main(){
  string line;
  unordered_map<string, int> m;
  while (getline(cin, line) && line != "0"){
    stringstream check1(line);
    string temp;
    vector<string> s;
    while (getline(check1, temp, ' ')){
      s.push_back(temp);
    }
    if (s.size() > 1 && s[1] == "="){
      m[s[0]] = stoi(s[2]);
    }
    else{
      int sum = 0;
      vector<string> undeclared;
      for (auto it = s.begin(); it != s.end(); it++){
        if (isdigit((*it)[0])){
          sum += stoi(*it);
        }
        else if (m.find(*it) != m.end()){
          sum += m[*it];
        }
        else if (*it != "+"){
          undeclared.push_back(*it);
        }
      }
      if (sum != 0){
        cout << sum;
        if (!undeclared.empty()){
          for (auto is = undeclared.begin(); is != undeclared.end(); is++){
            cout << " + " << *is;
          }
        }
        cout << endl;
      }
      else{
        if (!undeclared.empty()){
          for (auto is = undeclared.begin(); is != --undeclared.end(); is++){
            cout << *is << " + ";
          }
          cout << undeclared[undeclared.size() - 1];
        }
        else{
          cout << 0;
        }
        cout << endl;
      }
    }
  }
}
