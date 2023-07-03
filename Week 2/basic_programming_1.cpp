#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int n, t;
  cin >> n >> t;
  vector<ll> v;
  for (int i = 0; i < n; i++){
    ll ele;
    cin >> ele;
    v.push_back(ele);
  }
  if (t == 1){
    cout << 7 << endl;
  }
  else if (t == 2){
    if (v[0] > v[1]){
      cout << "Bigger\n";
    }
    else if (v[0] == v[1]){
      cout << "Equal\n";
    }
    else{
      cout << "Smaller\n";
    }
  }
  else if (t == 3){
    vector<ll> temp;
    temp.push_back(v[0]);
    temp.push_back(v[1]);
    temp.push_back(v[2]);
    sort(temp.begin(), temp.end());
    cout << temp[1] << endl;
  }
  else if (t == 4){
    ll result = 0;
    for (int j = 0; j < n; j++){
      result += v[j];
    }
    cout << result << endl;
  }
  else if (t == 5){
    ll result = 0;
    for (int j = 0; j < n; j++){
      if (v[j]%2 == 0){
        result += v[j];
      }
    }
    cout << result << endl;
  }
  else if (t == 6){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    for (int j = 0; j < n; j++){
      result += alphabet[v[j]%26];
    }
    cout << result << endl;
  }
  else if (t == 7){
    unordered_map<ll, bool> visited;
    ll index = 0;
    visited[0] = true;
    for (int j = 0; j < n; j++){
      index = v[index];
      if (index >= n){
        cout << "Out\n";
        return 0;
      }
      else if (index == n-1){
        cout << "Done\n";
        return 0;
      }
      else if (visited.find(index) != visited.end()){
        cout << "Cyclic\n";
        return 0;
      }
      else{
        visited[index] = true;
      }
    }
    cout << "Cycluc\n";
  }
}
