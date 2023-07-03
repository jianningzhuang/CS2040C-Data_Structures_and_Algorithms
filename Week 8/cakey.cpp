#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int n;
  cin >> n;
  int m;
  cin >> m;
  set<ll> setin;
  set<ll> setout;
  for (int i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    setin.insert(temp);
  }
  for (int i = 0; i < m; i++){
    ll temp;
    cin >> temp;
    setout.insert(temp);
  }
  map<int, int> ma;
  for (auto it = setin.begin(); it != setin.end(); it++){
    for (auto is = setout.begin(); is != setout.end(); is++){
      if (*is > *it){
        ma[(*is - *it)]++;
      }
    }
  }
  ll largest = 0;
  ll result = 0;
  for (auto it = ma.begin(); it != ma.end(); it++){
    if (it->second > largest){
      largest = it->second;
      result = it->first;
    }
  }
  cout << result << endl;
}
