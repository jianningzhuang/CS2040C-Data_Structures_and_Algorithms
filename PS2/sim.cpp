#include <bits/stdc++.h>
using namespace std;

void display_message(string line){
  list<char> message;
  int index = 0;
  for (auto &c : line){
    if (c == '['){
      index = 0;
    }
    else if (c == ']'){
      index = message.size();
    }
    else if (c == '<'){
      if (index == 0 || message.empty()){
        continue;
      }
      if (index == message.size()){
        message.pop_back();
        index--;
      }
      else{
        list<char>::iterator cursor = message.begin();
        advance(cursor, index - 1);
        message.erase(cursor);
        index--;
      }
    }
    else{
      if (index == 0){
        message.push_front(c);
        index++;
      }
      else if (index == message.size()){
        message.push_back(c);
        index++;
      }
      else{
        list<char>::iterator cursor = message.begin();
        advance(cursor, index);
        message.insert(cursor, c);
        index++;
      }
    }
  }
  for (list<char>::iterator i = message.begin(); i != message.end(); i++){
    cout << *i;
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  cin.ignore();
  for (int i = 0; i < T; i++){
    string line;
    getline(cin, line);
    display_message(line);
  }
}
