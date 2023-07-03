#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_map<string, vector<int>> memory;
  for (int i = 0; i < n; i++){
    string name;
    int year;
    cin >> name >> year;
    memory[name].push_back(year);
  }
  for (auto i = memory.begin(); i != memory.end(); i++){
    sort((i->second).begin(), (i->second).end());
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string name;
    int k;
    cin >> name >> k;
    cout << memory[name][k - 1] << endl;
  }
}
