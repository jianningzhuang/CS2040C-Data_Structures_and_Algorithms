#include <bits/stdc++.h>
using namespace std;

//2:00 to

typedef unsigned long long ll;

struct compare{
  bool operator()(const pair<string, ll> p1, const pair<string, ll> p2) const{
    if (p1.second == p2.second){
      return lexicographical_compare(p1.first.begin(), p1.first.end(), p2.first.begin(), p2.first.end());
    }
    else{
      return p1.second > p2.second;
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  set<pair<string, ll>, compare> set1;
  set<pair<string, ll>, compare> set2;
  set<pair<string, ll>, compare> set3;
  unordered_map<string, vector<ll>> stats;
  for (int i = 0; i < n; i++){
    string name;
    ll s1, s2, s3;
    cin >> name >> s1 >> s2 >> s3;
    set1.insert({name, s1});
    set2.insert({name, s2});
    set3.insert({name, s3});
    stats[name] = {s1, s2, s3};
  }
  for (int i = 0; i < n/3; i++){
    string member1 = (set1.begin())->first;
    set1.erase({member1, stats[member1][0]});
    set2.erase({member1, stats[member1][1]});
    set3.erase({member1, stats[member1][2]});
    string member2 = (set2.begin())->first;
    set1.erase({member2, stats[member2][0]});
    set2.erase({member2, stats[member2][1]});
    set3.erase({member2, stats[member2][2]});
    string member3 = (set3.begin())->first;
    set1.erase({member3, stats[member3][0]});
    set2.erase({member3, stats[member3][1]});
    set3.erase({member3, stats[member3][2]});
    vector<string> order = {member1, member2, member3};
    sort(order.begin(), order.end(), [](string a, string b){return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());});
    cout << order[0] << " " << order[1] << " " << order[2] << endl;
  }
}
