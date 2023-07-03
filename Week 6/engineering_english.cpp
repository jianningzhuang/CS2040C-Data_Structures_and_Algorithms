#include <bits/stdc++.h>
using namespace std;

int main(){
  unordered_set<string> duplicates;
  string line;
  while (getline(cin, line)){
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ' ')){
      tokens.push_back(token);
    }
    for (auto &s : tokens){
      string temp = "";
      for (auto &c : s){
        temp += tolower(c);
      }
      if (duplicates.find(temp) != duplicates.end()){
        cout << ". ";
      }
      else{
        duplicates.insert(temp);
        cout << s << " ";
      }
    }
    cout << endl;
  }
}
