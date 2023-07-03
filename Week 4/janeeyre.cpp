#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<string, ll> sl;


int main(){
  ll n, m, k;
  cin >> n >> m >> k;
  priority_queue<sl, vector<sl>, greater<sl>> pile;
  pile.push({"Jane Eyre", k});
  for (ll i = 0; i < n; i++){
    string s, title, delimiter = "\"";
    ll pages;
    getline(cin, s);
    s.erase(0, 1);
    title = s.substr(0, s.find(delimiter));
    s.erase(0, s.find(delimiter) + delimiter.length() + 1);
    pages = stoi(s);
    pile.push({title, pages});
  }
  cout << pile.top().first;
  for (ll i = 0; i < m; i++){
    string title;
    ll time, pages;
    cin >> time >> title >> pages;
  }
  cout << pile.top().first;
}
