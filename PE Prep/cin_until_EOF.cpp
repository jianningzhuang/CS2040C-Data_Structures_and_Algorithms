#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> v;
  string word;
  while (getline(cin, word)){
    if (word == ""){
      sort(v.begin(), v.end(), compare);
      printgroup(v);
      cout << endl;
      v.clear();
    }
    else{
      v.push_back(word);
    }
  }
  sort(v.begin(), v.end(), compare);
  printgroup(v);
}
