#include <bits/stdc++.h>
using namespace std;

int main(){
  int r, c;
  cin >> r >> c;
  while (r != 0 && c != 0){
    vector<vector<char>> v(r);
    vector<vector<char>> sorted(r);
    vector<pair<char, char>> fake;
    for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++){
        char c;
        cin >> c;
        v[i].push_back(c);
        sorted[i].push_back('a');
        if (i == 0){
          fake.push_back({tolower(c), c});
        }
      }
    }
    unordered_map<char, int> m;
    for (int i = 0; i < c; i++){
      m[v[0][i]] = i;
    }
    stable_sort(fake.begin(), fake.end());
    for (int i = 0; i < c; i++){
      sorted[0][i] = fake[i].second;
    }
    for (int i = 1; i < r; i++){
      for (int j = 0; j < c; j++){
        sorted[i][j] = v[i][m[sorted[0][j]]];
      }
    }
    for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++){
        cout << sorted[i][j];
      }
      cout << endl;
    }
    cout << endl;
    cin >> r >> c;
  }
}
