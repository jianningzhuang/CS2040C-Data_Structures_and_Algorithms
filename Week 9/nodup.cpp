#include <bits/stdc++.h>
using namespace std;

// int main(){
//   string line;
//   getline(cin, line);
//   unordered_set<string> s;
//   string curr = "";
//   for (auto &c : line){
//     if (c == ' '){
//       if (s.find(curr) != s.end()){
//         cout << "no\n";
//         return 0;
//       }
//       else{
//         s.insert(curr);
//         curr = "";
//       }
//     }
//     else{
//       curr += c;
//     }
//   }
//   if (s.find(curr) != s.end()){
//     cout << "no\n";
//     return 0;
//   }
//   cout << "yes\n";
// }

int main(){
  unordered_set<string> s;
  string line;
  getline(cin, line);
  stringstream check1(line);
  string temp;
  while (getline(check1, temp, ' ')){
    if (s.find(temp) != s.end()){
      cout << "no\n";
      return 0;
    }
    else{
      s.insert(temp);
    }
  }
  cout << "yes\n";
}
