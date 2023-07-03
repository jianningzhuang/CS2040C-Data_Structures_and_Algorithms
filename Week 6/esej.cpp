#include <bits/stdc++.h>
using namespace std;

int main(){
  srand (time(NULL));
  int a, b;
  cin >> a >> b;
  unordered_set<string> s;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < b; i++){
    string word = "";
    for (int j = 0; j < 15; j++){
      int letter = rand() % 26;
      word += alphabet[letter];
    }
    s.insert(word);
  }
  for (auto i = s.begin(); i != s.end(); i++){
    cout << *i << " ";
  }
}
