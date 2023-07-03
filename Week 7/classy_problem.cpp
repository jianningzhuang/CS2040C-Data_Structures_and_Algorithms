#include <bits/stdc++.h>
using namespace std;

// 4:45 to 5:20 pass 1 only
// 5:27 give up

bool lexi(string a, string b){
  while (a.front() == b.front()){
    a.erase(a.begin());
    b.erase(b.begin());
    if (a.empty()){
      return true;
    }
    else if (b.empty()){
      return false;
    }
  }
  return a.front() < b.front();
}

bool compare(pair<string, vector<string>> a, pair<string, vector<string>> b){
  while ((a.second).back() == (b.second).back()){
    (a.second).pop_back();
    (b.second).pop_back();
    if ((a.second).empty() || (b.second).empty()){
      return lexi(a.first, b.first);
    }
  }
  return ((a.second).back() > (b.second).back());
}

int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<string, vector<string>>> names;
    for (int j = 0; j < n; j++){
      string line;
      getline(cin, line);
      string name = "";
      string subclass = "";
      vector<string> classy;
      int count = 0;
      for (auto &c : line){
        if (c != ' ' && count == 0){
          name += c;
        }
        else if (c == ' ' && count == 0){
          count++;
        }
        else if (c == ' ' && count == 1){
          count++;
        }
        else if (c != '-' && count == 1){
          subclass += c;
        }
        else if (c == '-'){
          classy.push_back(subclass);
          subclass = "";
        }
        else if (c == 'c' && count == 2){
          classy.push_back(subclass);
        }
      }
      name.pop_back();
      names.push_back({name, classy});
    }
    sort(names.begin(), names.end(), compare);
    for (int k = 0; k < names.size(); k++){
      cout << names[k].first << endl;
    }
    cout << "==============================\n";
  }
}
