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
    for (int i = 0; i <  longest - s.size(); i++){
      cout << " ";
    }
    cout << s << endl;
  }
}

bool compare(string a, string b){
  while (a.back() == b.back()){
    a.pop_back();
    b.pop_back();
    if (a.empty()){
      return true;
    }
    else if (b.empty()){
      return false;
    }
  }
  return a.back() < b.back();
}

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
