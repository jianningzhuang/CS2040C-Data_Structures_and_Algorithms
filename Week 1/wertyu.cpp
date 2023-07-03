#include <iostream>
using namespace std;

int main(){
  string dict[4] = {"1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
  while (true){
    string line;
    getline(cin, line);
    if (cin.eof()){
      break;
    }
    for (auto &c: line){
      if (c == ' '){
        cout << ' ';
      }
      else{
        for (int i = 0; i < 4; i++){
          for (int j = 0; j < int(dict[i].length()); j++){
            if (dict[i][j] == c){
              cout << dict[i][j-1];
            }
          }
        }
      }
    }
    cout << "\n";
  }
}
