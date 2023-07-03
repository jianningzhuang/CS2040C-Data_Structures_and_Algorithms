//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<set<pair<int, int>>> school;
vector<set<pair<int, pair<int, int>>>> students;
vector<multiset<ll>> steps;
vector<ll> minsteps;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, f, s, g;
  cin >> r >> c >> f >> s >> g;
  school.assign(f+1, set<pair<int, int>>());
  for (int i = 1; i <= f; i++){
    int k;
    cin >> k;
    for (int j = 0; j < k; j++){
      int x, y;
      cin >> x >> y;
      school[i].insert({x, y});
    }
  }
  students.assign(f+1, set<pair<int, pair<int, int>>>());
  for (int i = 0; i < s; i++){
    int x, y, id, faculty;
    cin >> x >> y >> id >> faculty;
    students[faculty].insert({id, {x, y}});
  }
  steps.assign(f+1, multiset<ll>());
  for (int i = 1; i <= f; i++){
    for (auto it = students[i].begin(); it != students[i].end(); it++){
      pair<int, int> curr = it->second;
      pair<int, int> final = *(school[i].begin());
      school[i].erase(school[i].begin());
      //cout << abs(curr.first - final.first) + abs(curr.second - final.second) << endl;
      steps[i].insert(abs(curr.first - final.first) + abs(curr.second - final.second));
    }
  }
  minsteps.assign(f+1, 0);
  for (int i = 1; i <= f; i++){
    int t;
    cin >> t;
    auto is = steps[i].begin();
    for (int j = 0; j < t; j++){
      minsteps[i] += *(is);
      is++;
    }
  }
  sort(minsteps.begin(), minsteps.end());
  ll total = 0;
  for (int i = i; i <= g; i++){
    total += minsteps[i];
  }
  cout << total << endl;


}
