#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

bool attack(vector<int> v1, vector<int> v2){
  return v1[0] > v2[0];
}
bool defense(vector<int> v1, vector<int> v2){
  return v1[1] > v2[1];
}
bool health(vector<int> v1, vector<int> v2){
  return v1[2] > v2[2];
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> pokemon(n);
  for (int i = 0; i < n; i++){
    ll a, d, h;
    cin >> a >> d >> h;
    pokemon[i].push_back(a);
    pokemon[i].push_back(d);
    pokemon[i].push_back(h);
    pokemon[i].push_back(i);
  }
  unordered_set<int> top;
  sort(pokemon.begin(), pokemon.end(), attack);
  for (int i = 0; i < k; i++){
    if (top.find(pokemon[i][3]) == top.end()){
      top.insert(pokemon[i][3]);
    }
  }
  sort(pokemon.begin(), pokemon.end(), defense);
  for (int i = 0; i < k; i++){
    if (top.find(pokemon[i][3]) == top.end()){
      top.insert(pokemon[i][3]);
    }
  }
  sort(pokemon.begin(), pokemon.end(), health);
  for (int i = 0; i < k; i++){
    if (top.find(pokemon[i][3]) == top.end()){
      top.insert(pokemon[i][3]);
    }
  }
  cout << top.size();
}
