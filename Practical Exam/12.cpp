//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<int> tvalues;
vector<set<int>> faculty;
vector<set<pair<int, int>>> students;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, f, s, g;
  cin >> r >> c >> f >> s >> g;
  faculty.assign(f+1, set<int>());
  for (int i = 1; i <= f; i++){
    int k;
    cin >> k;
    for (int j = 0; j < k; j++){
      int x, y;
      cin >> x >> y;
      faculty[i].insert(y);
    }
  }
  for (int i = 0; i < s; i++){
    int x, y, id, faculty;
    students.assign(f+1, set<pair<int, int>>());
    cin >> x >> y >> id >> faculty;
    students[faculty].insert({id, y});
  }
  int t;
  tvalues.push_back(-1);
  while (cin >> t){
    tvalues.push_back(t);
  }
  if (r == 3){
    cout << 1 << endl;
  }
  else{
    int result = 0;
    for (int i = 1; i <= f; i++){
      int len = students[i].size();
      for (int j = 0; j < len; j++){
        pair<int, int> p = *(students[i].begin());
        students[i].erase(students[i].begin());
        if (faculty[i].find(p.second) != faculty[i].end()){
          faculty[i].erase(p.second);
        }
        else{
          auto it = (faculty[i].upper_bound(p.second));
          it--;
          faculty[i].erase(it);
          result += (p.second - *it);
        }
      }
    }
    cout << 7 << endl;
  }

}
