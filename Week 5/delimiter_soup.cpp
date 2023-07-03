#include <bits/stdc++.h>
using namespace std;

int main(){
  int l;
  cin >> l;
  cin.ignore();
  string line;
  getline(cin, line);
  stack<char> s;
  int index = -1;
  for (auto &c : line){
    index++;
    if (c == ' '){
      continue;
    }
    else if (c == ')'){
      if (s.empty() || s.top() != '('){
        cout << ") " << index;
        return 0;
      }
      else{
        s.pop();
      }
    }
    else if (c == '}'){
      if (s.empty() || s.top() != '{'){
        cout << "} " << index;
        return 0;
      }
      else{
        s.pop();
      }
    }
    else if (c == ']'){
      if (s.empty() || s.top() != '['){
        cout << "] " << index;
        return 0;
      }
      else{
        s.pop();
      }
    }
    else{
      s.push(c);
    }
  }
  cout << "ok so far";
}
