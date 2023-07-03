#include <bits/stdc++.h>
using namespace std;

bool adventure(string a){
  stack<char> s;
  for (auto &c : a){
    if (c == '$' || c == '|' || c == '*'){
      s.push(c);
    }
    else if (c == 't'){
      if (s.empty()){
        return false;
      }
      if (s.top() != '|'){
        return false;
      }
      s.pop();
      continue;
    }
    else if (c == 'j'){
      if (s.empty()){
        return false;
      }
      if (s.top() != '*'){
        return false;
      }
      s.pop();
      continue;
    }
    else if (c == 'b'){
      if (s.empty()){
        return false;
      }
      if (s.top() != '$'){
        return false;
      }
      s.pop();
      continue;
    }
  }
  if (s.empty()){
    return true;
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++){
    string a;
    getline(cin, a);
    if (adventure(a)){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}
