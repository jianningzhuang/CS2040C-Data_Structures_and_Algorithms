#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    map<string, vector<int>> carcost;
    map<string, vector<char>> log;
    map<string, int> pay;
    map<string, string> driving;
    map<string, int> user;
    set<string> inconsistent;
    int n, m;
    cin >> n >> m;
    for (int j = 0; j < n; j++){
      string car;
      int p, q, k;
      cin >> car >> p >> q >> k;
      carcost[car] = {p, q, k};
    }
    for (int j = 0; j < m; j++){
      int t;
      string name;
      char e;
      cin >> t >> name >> e;
      if (e == 'p'){
        string type;
        cin >> type;
        if (log[name].empty() || log[name].back() == 'r'){
          if (user[type] == 0){
            log[name].push_back('p');
            pay[name]+=carcost[type][1];
            driving[name] = type;
            user[type] = 1;
          }
          else{
            pay[name] += 0;
            inconsistent.insert(name);
          }
        }
        else{
          pay[name] += 0;
          inconsistent.insert(name);
        }
      }
      else if (e == 'r'){
        int distance;
        cin >> distance;
        if (log[name].empty() || log[name].back() == 'r'){
          pay[name] += 0;
          inconsistent.insert(name);
        }
        else{
          log[name].push_back('r');
          pay[name]+=(carcost[driving[name]][2] * distance);
          user[driving[name]] = 0;
          driving[name] = "";

        }
      }
      else if (e == 'a'){
        int severity;
        cin >> severity;
        if (log[name].empty() || log[name].back() == 'r'){
          pay[name] += 0;
          inconsistent.insert(name);
        }
        else{
          log[name].push_back('a');
          pay[name]+=(carcost[driving[name]][0] * 100 /severity);
        }
      }
    }
    for (auto it = pay.begin(); it != pay.end(); it++){
      if (inconsistent.find(it->first) != inconsistent.end()){
        cout << it->first << " INCONSISTENT\n";
      }
      else{
        cout << it->first << " " << it->second << endl;
      }
    }
  }


}
