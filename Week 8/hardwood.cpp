#include <bits/stdc++.h>
using namespace std;

int main(){
  map<string, int> m;
  int total = 0;
  string line;
  while (getline(cin, line) && line != "Jianning"){
    m[line]++;
    total++;
  }
  for (auto it = m.begin(); it != m.end(); it++){
    double pc = double(it->second)*100/total;
    cout << it->first << " " << fixed << setprecision(4) << pc << endl;
  }
}
