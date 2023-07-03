#include <bits/stdc++.h>
using namespace std;

void print_stack(stack<char> s){
  while (!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main(){
  stack<char> s1;
  stack<char> s2;
  string expression;
  getline(cin, expression);
  for (auto &c : expression){
    if (c == ' '){
      continue;
    }
    else if (c == ')'){
      while (s1.top() != '('){
        s2.push(s1.top());
        s1.pop();
      }
      s1.pop();
      while (!s2.empty()){

      }
    }
    else{
      s1.push(c);
    }
  }
}
