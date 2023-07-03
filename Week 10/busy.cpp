#include <bits/stdc++.h>
using namespace std;

bool compare(vector<string> v1, vector<string> v2){
  if (v1[2] == v2[2]){
    if (v1[0] == v2[0]){
      return stoi(v1[1]) < stoi(v2[1]);
    }
    else{
      if (v1[0] == "12"){
        return true;
      }
      else if (v2[0] == "12"){
        return false;
      }
      else{
        return stoi(v1[0]) < stoi(v2[0]);
      }
    }
  }
  else{
    return v1[2] == "a.m.";
  }
}

int main(){
  int n;
  while (cin >> n && n != 0){
    vector<vector<string>> v;
    for (int i = 0; i < n; i++){
      string time, ap;
      cin >> time >> ap;
      string hour = "";
      string min = "";
      bool flag = true;
      for (auto &c : time){
        if (c == ':'){
          flag = false;
        }
        else if (flag){
          hour += c;
        }
        else{
          min += c;
        }
      }
      v.push_back({hour, min, ap});
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++){
      cout << v[i][0] << ":" << v[i][1] << " " << v[i][2] << endl;
    }
  }
}
