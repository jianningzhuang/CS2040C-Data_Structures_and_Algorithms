#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<string> s, int max){
  for (auto i = s.begin(); i != s.end(); i++){
    int len = i->length();
    int spaces = max - len;
    for (int j = 0; j < spaces; j++){
      cout << " ";
    }
    cout << *i << endl;
  }
}


bool last(string a, string b){
  while (a.back() == b.back()){
    a.pop_back();
    b.pop_back();
  }
  return a.back() < b.back();
}

int main(){
  vector<string> s;
  string word;
  int max = 0;
  while (getline(cin, word)){
    if (word.length() == 0){
      sort(s.begin(), s.end(), last);
      print_vector(s, max);
      cout << endl;
      s.clear();
      max = 0;
    }
    else{
      if (word.length() > max){
        max = word.length();
      }
      s.push_back(word);
    }
  }
  sort(s.begin(), s.end(), last);
  print_vector(s, max);
}
