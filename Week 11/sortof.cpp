#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
  if (a == b){
    return false;
  }
  if (a[0] == b[0]){
    if (a[1] == b[1]){
      return false;
    }
    else{
      return a[1] < b[1];
    }
  }
  else{
    return a[0] < b[0];
  }
}

int main(){
  int n;
  while (cin >> n && n != 0){
    vector<string> v;
    for (int i = 0; i < n; i++){
      string name;
      cin >> name;
      v.push_back(name);
    }
    sort(v.begin(), v.end(), compare);
    for (auto &s : v){
      cout << s << endl;
    }
    cout << endl;
  }
}
