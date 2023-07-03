#include <bits/stdc++.h>
using namespace std;

int main(){
  int m, n;
  cin >> m >> n;
  unordered_map<string, int> points;
  for (int i = 0; i < m; i++){
    string word;
    int val;
    cin >> word >> val;
    points[word] = val;
  }
  for (int i = 0; i < n; i++){
    int total = 0;
    string line;
    while (cin >> line && line != "."){
      total += points[line];
    }
    cout << total << endl;
  }
}
