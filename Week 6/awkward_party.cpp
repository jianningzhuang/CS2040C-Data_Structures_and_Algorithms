#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_map<int, pair<int, int>> awk;
  for (int i = 0; i < n; i++){
    int guest;
    cin >> guest;
    if (awk.find(guest) == awk.end()){
      awk[guest] = {i, n};
    }
    else{
      if ((i - awk[guest].first) < awk[guest].second){
        awk[guest] = {i, i - awk[guest].first};
      }
      else{
        awk[guest] = {i, awk[guest].second};
      }
    }
  }
  int min = n;
  for (auto i = awk.begin(); i != awk.end(); i++){
    if ((i->second).second < min){
      min = (i->second).second;
    }
  }
  cout << min;
}
