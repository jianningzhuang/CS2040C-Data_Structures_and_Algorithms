#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<pair<int, int>> adj = {{2018, 0}, {-2018, 0}, {0, 2018}, {0, -2018},
{1118, 1680}, {-1118, 1680}, {1118, -1680}, {-1118, -1680}, {1680, 1118}, {-1680, 1118}, {1680, -1118}, {-1680, -1118}};

int main(){
  int n;
  cin >> n;
  unordered_set<string> s;
  ll count = 0;
  for (int i = 0; i < n; i++){
    ll a, b;
    cin >> a >> b;
    for (auto &p : adj){
      ll a1 = a + p.first;
      ll b1 = b + p.second;
      if (a1 >= 0 && b1 >= 0){
        string temp1 = to_string(a1) + to_string(b1);
        if (s.find(temp1) != s.end()){
          count++;
        }
      }
    }
    string temp = to_string(a) + to_string(b);
    s.insert(temp);
  }
  cout << count << endl;
}
