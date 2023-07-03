#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  unordered_set<string> s;
  for (int i = 0; i < n; i++){
    string line;
    getline(cin, line);
    string parsed = "";
    for (auto &c: line){
      if (c == '-'){
        parsed += ' ';
      }
      else if (isupper(c)){
        parsed += tolower(c);
      }
      else{
        parsed += c;
      }
    }
    s.insert(parsed);
  }
  cout << s.size() << endl;
}
