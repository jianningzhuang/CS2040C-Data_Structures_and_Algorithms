#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, p, m;
  cin >> n >> p >> m;
  unordered_map<string, int> score;
  for (int i = 0; i < n; i++){
    string name;
    cin >> name;
    score[name] = 0;
  }
  int count = 0;
  for (int i = 0; i < m; i++){
    string name;
    int points;
    cin >> name >> points;
    score[name] += points;
    if (score[name] >= p){
      count++;
      cout << name << " wins!\n";
      score[name] = -1000000;
    }
  }
  if (count == 0){
    cout << "No winner!\n";
  }
}
