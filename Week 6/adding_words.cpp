#include <bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<string, int> num;
  while (!cin.eof()){
    vector<string> tokens;
    string line;
    getline(cin, line);
    stringstream check1(line);
    string token;
    while (getline(check1, token, ' ')){
      tokens.push_back(token);
    }
    if (tokens[0] == "def"){
      num[tokens[1]] = stoi(tokens[2]);
    }
    else if (tokens[0] == "calc"){
      int value = 0;
      int sign = 1;
      int flag = 0;
      for (auto &w : tokens){
        if (w == "-"){
          sign = -1;
          cout << w << " ";
        }
        else if (w == "+"){
          sign = 1;
          cout << w << " ";
        }
        else if (w == "="){
          cout << w << " ";
          if (flag == 1){
            cout << "unknown\n";
            break;
          }
          else{
            int found = 0;
            for (auto i = num.begin(); i != num.end(); i++){
              if (i->second == value){
                cout << i->first << endl;
                found = 1;
                break;
              }
            }
            if (found == 0){
              cout << "unknown\n";
            }
          }
        }
        else if (w != "def" && w != "calc"){
          cout << w << " ";
          if (num.find(w) == num.end()){
            flag = 1;
          }
          else{
            value += num[w]*sign;
          }
        }
      }
    }
    else if (tokens[0] == "clear"){
      num.clear();
    }
  }
}
