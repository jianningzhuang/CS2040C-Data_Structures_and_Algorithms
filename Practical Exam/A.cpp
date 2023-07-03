//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<vector<pair<int, int>>> school;
vector<int> tvalues;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, f, s, g;
  cin >> r >> c >> f >> s >> g;
  school.assign(f+1, vector<pair<int, int>>());
  for (int i = 1; i <= f; i++){
    int k;
    cin >> k;
    for (int j = 0; j < k; j++){
      int x, y;
      cin >> x >> y;
      school[i].push_back({x, y});
    }
  }
  for (int i = 0; i < s; i++){
    int x, y, id, faculty;
    cin >> x >> y >> id >> faculty;

  }
  int t;
  tvalues.push_back(-1);
  while (cin >> t){
    tvalues.push_back(t);
  }
  cout << 1 << endl;

}
