#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

bool lexicographic(string s1, string s2){
  int len1 = s1.length();
  int len2 = s2.length();
  if (len1 >= len2){
    for (int i = 0; i < len2; i++){
      if (int(s1[i]) < int(s2[i])){
        return true;
      }
      else if (int(s1[i]) > int(s2[i])){
        return false;
      }
    }
    return false;
  }
  else{
    for (int i = 0; i < len1; i++){
      if (int(s1[i]) < int(s2[i])){
        return true;
      }
      else if (int(s1[i]) > int(s2[i])){
        return false;
      }
    }
    return true;
  }
}

struct compare{
  bool operator()(pair<ll, string> p1, pair<ll, string> p2) const{
    if (p1.first == p2.first){
      return lexicographic(p2.second, p1.second);
    }
    else{
      return p1.first > p2.first;
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  set<pair<ll, string>, compare> set1;
  set<pair<ll, string>, compare> set2;
  set<pair<ll, string>, compare> set3;
  unordered_map<string, vector<ll>> stats;
  for (int i = 0; i < n; i++){
    string name;
    ll s1, s2, s3;
    cin >> name >> s1 >> s2 >> s3;
    set1.insert({s1, name});
    set2.insert({s2, name});
    set3.insert({s3, name});
    stats[name].push_back(s1);
    stats[name].push_back(s2);
    stats[name].push_back(s3);
  }
  while (true){
    vector<string> order;
    if (set1.empty()){
      break;
    }
    else{
      set<pair<ll, string>>::iterator p1 = set1.begin();
      string name1 = p1->second;
      order.push_back(name1);
      set2.erase(set2.find({stats[name1][1], name1}));
      set3.erase(set3.find({stats[name1][2], name1}));
      set1.erase(p1);
    }
    if (set2.empty()){
      break;
    }
    else{
      set<pair<ll, string>>::iterator p2 = set2.begin();
      string name2 = p2->second;
      order.push_back(name2);
      set3.erase(set3.find({stats[name2][2], name2}));
      set1.erase(set1.find({stats[name2][0], name2}));
      set2.erase(p2);
    }
    if (set3.empty()){
      break;
    }
    else{
      set<pair<ll, string>>::iterator p3 = set3.begin();
      string name3 = p3->second;
      order.push_back(name3);
      set2.erase(set2.find({stats[name3][1], name3}));
      set1.erase(set1.find({stats[name3][0], name3}));
      set3.erase(p3);
    }
    sort(order.begin(), order.end(), lexicographic);
    for (auto it = order.begin(); it != order.end(); it++){
      cout << *it << " ";
    }
    cout << endl;
  }
}
