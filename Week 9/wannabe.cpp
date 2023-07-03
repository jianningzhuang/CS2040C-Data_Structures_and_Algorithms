#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int n, k;
  cin >> n >> k;
  set<pair<ll, int>, greater<pair<ll, int>>> attack;
  set<pair<ll, int>, greater<pair<ll, int>>> defense;
  set<pair<ll, int>, greater<pair<ll, int>>> health;
  for (int i = 0; i < n; i++){
    ll a, d, h;
    cin >> a >> d >> h;
    attack.insert({a, i});
    defense.insert({d, i});
    health.insert({h, i});
  }
  unordered_set<int> final;
  for (int i = 0; i < k; i++){
    auto a = attack.begin();
    final.insert(a->second);
    attack.erase(a);
    auto d = defense.begin();
    final.insert(d->second);
    defense.erase(d);
    auto h = health.begin();
    final.insert(h->second);
    health.erase(h);
  }
  cout << final.size() << endl;
}
