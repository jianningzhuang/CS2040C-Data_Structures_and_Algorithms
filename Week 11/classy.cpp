#include <bits/stdc++.h>
using namespace std;

//start 1127 to

bool compare(pair<string, vector<string>> p1, pair<string, vector<string>> p2){
  while (p1.second.back() == p2.second.back()){
    p1.second.pop_back();
    p2.second.pop_back();
    if (p1.second.empty() && p2.second.empty()){
      return lexicographical_compare(p1.first.begin(), p1.first.end(), p2.first.begin(), p2.first.end());
    }
    else if (p1.second.empty()){
      while (p2.second.back() == "middle"){
        p2.second.pop_back();
        if (p2.second.empty()){
          return lexicographical_compare(p1.first.begin(), p1.first.end(), p2.first.begin(), p2.first.end());
        }
      }
      return p2.second.back() < "middle";
    }
    else if (p2.second.empty()){
      while (p1.second.back() == "middle"){
        p1.second.pop_back();
        if (p1.second.empty()){
          return lexicographical_compare(p1.first.begin(), p1.first.end(), p2.first.begin(), p2.first.end());
        }
      }
      return p1.second.back() > "middle";
    }
  }
  return p1.second.back() > p2.second.back();
}

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<string, vector<string>>> v;
    for (int j = 0; j < n; j++){
      string line;
      getline(cin, line);
      stringstream check1(line);
      string temp;
      vector<string> person;
      while (getline(check1, temp, ' ')){
        person.push_back(temp);
      }
      stringstream check2(person[1]);
      string temp1;
      vector<string> classes;
      while (getline(check2, temp1, '-')){
        classes.push_back(temp1);
      }
      string name = person[0];
      name.pop_back();
      v.push_back({name, classes});
    }
    sort(v.begin(), v.end(), compare);
    for (auto it = v.begin(); it != v.end(); it++){
      cout << it->first << endl;
    }
    cout << "==============================\n";
  }
}
