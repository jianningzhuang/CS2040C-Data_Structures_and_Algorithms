#include <bits/stdc++.h>
using namespace std;

void display_message(string line){
  list<char> message;
  int cursor = 0;
  for (auto &c : line){
    if (c == '['){
      cursor = 0;
    }
    else if (c == ']'){
      cursor = 1
    }
    else if (c == '<'){
      if (cursor == 0 || message.empty()){
        continue;
      }
      else{
        message.pop_back();
      }
    }
    else{
      if (cursor == 0){
        message.push_front(c);
      }
      else if (cursor == message.end()){
        message.push_back(c);
      }
      else{
        cursor = message.insert(cursor, c);
      }
    }
  }
  for (list<char>::iterator i = message.begin(); i != message.end(); i++){
    cout << *i;
  }
  cout << endl;
}

int main(){
  int T;
  cin >> T;
  cin.ignore();
  for (int i = 0; i < T; i++){
    string line;
    getline(cin, line);
    display_message(line);
  }
}
