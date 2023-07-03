#include <bits/stdc++.h>
using namespace std;

bool match(char a, char b){
  if (a == '('){
    return b == ')';
  }
  else if (a == '['){
    return b == ']';
  }
  else if (a == '{'){
    return b == '}';
  }
  else if (a == '<'){
    return b == '>';
  }
}

bool bracket(string line, string stack){
  if (line.empty()){
    return stack.empty();
  }
  else if (line[0] == '(' || line[0] == '[' || line[0] == '{' || line[0] == '<'){
    stack += line[0];
    line.erase(line.begin());
    return bracket(line, stack);
  }
  else if (line[0] == ')' || line[0] == ']' || line[0] == '}' || line[0] == '>'){
    cout << line[0] << stack.back() << endl;
    if (!stack.empty() && match(stack.back(), line[0])){
      stack.pop_back();
      line.erase(line.begin());
      return bracket(line, stack);
    }
  }
  else {
    return false;
  }
}

int main(){
  string line;
  cin >> line;
  if (bracket(line, "")){
    cout << "yes\n";
  }
  else{
    cout << "no\n";
  }
}
