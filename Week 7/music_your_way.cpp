#include <bits/stdc++.h>
using namespace std;

// 8:40 to

int main(){
  string attributes;
  getline(cin, attributes);
  vector<string> atr;
  string temp = "";
  for (auto &c : attributes){
    if (c != ' '){
      temp += c;
    }
    else{
      atr.push_back(temp);
      temp = "";
    }
  }
  atr.push_back(temp);
  int m;
  cin >> m;
  cin.ignore();
  vector<vector<string>> shuffle;
  for (int i = 0; i < m; i++){
    string song;
    getline(cin, song);
    vector<string> s;
    string temp1 = "";
    for (auto &c : song){
      if (c != ' '){
        temp1 += c;
      }
      else{
        s.push_back(temp1);
        temp1 = "";
      }
    }
    s.push_back(temp1);
    shuffle.push_back(s);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string command;
    cin >> command;
    int index;
    for (int j = 0; j < atr.size(); j++){
      if (atr[j] == command){
        index = j;
      }
    }
    stable_sort(shuffle.begin(), shuffle.end(), [index](vector<string> a, vector<string> b){
      return lexicographical_compare(a[index].begin(), a[index].end(), b[index].begin(), b[index].end());
    });
    for (int k = 0; k < atr.size(); k++){
      cout << atr[k] << " ";
    }
    cout << endl;
    for (int k = 0; k < shuffle.size(); k++){
      for (int l = 0; l < shuffle[k].size(); l++){
        cout << shuffle[k][l] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
