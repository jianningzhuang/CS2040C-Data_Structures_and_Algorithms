#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

//1243 to

int main(){
  int m;
  cin >> m;
  cin.ignore();
  unordered_map<string, set<string>> forum;
  unordered_map<string, ll> freq;
  for (int i = 0; i < m; i++){
    string line;
    getline(cin, line);
    stringstream check1(line);
    string temp;
    vector<string> v;
    while (getline(check1, temp, ' ')){
      v.push_back(temp);
    }
    for (int j = 1; j < v.size(); j++){
      forum[v[0]].insert(v[j]);
      freq[v[j]]++;
    }
  }
  map<ll, set<string>> result;
  set<string> chosen = forum.begin()->second;
  for (auto it = chosen.begin(); it != chosen.end(); it++){
    bool na = false;
    for (auto is = forum.begin(); is != forum.end(); is++){
      if ((is->second).find(*it) == (is->second).end()){
        na = true;
        break;
      }
    }
    if (!na){
      result[freq[*it]].insert(*it);
    }
  }
  if (result.empty()){
    cout << "ALL CLEAR\n";
  }
  else{
    for (auto it = result.rbegin(); it != result.rend(); it++){
      for (auto is = (it->second).begin(); is != (it->second).end(); is++){
        cout << *is << endl;
      }
    }
  }
}
