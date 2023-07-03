#include <bits/stdc++.h>
using namespace std;

//start 1008 to

void printgroup(vector<string> v){
  int longest = 0;
  for (auto &s : v){
    if (s.size() > longest){
      longest = s.size();
    }
  }
  for (auto &s : v){
    reverse(s.begin(), s.end());
    for (int i = 0; i <  longest - s.size(); i++){
      cout << " ";
    }
    cout << s << endl;
  }
}


int main(){
  vector<string> v;
  string word;
  while (getline(cin, word)){
    if (word == ""){
      sort(v.begin(), v.end());
      printgroup(v);
      cout << endl;
      v.clear();
    }
    else{
      reverse(word.begin(), word.end());
      v.push_back(word);
    }
  }
  sort(v.begin(), v.end());
  printgroup(v);
}
