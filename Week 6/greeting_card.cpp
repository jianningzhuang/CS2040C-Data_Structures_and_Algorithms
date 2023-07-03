#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int n;
  cin >> n;
  set<pair<ll, ll>> s;
  vector<pair<ll, ll>> v;
  int count = 0;
  for (int i = 0; i < n; i++){
    ll x, y;
    cin >> x >> y;
    pair<ll, ll> p;
    p.first = x;
    p.second = y;
    v.push_back(p);
    s.insert(p);
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if (s.find({i->first + 0, i->second + 2018}) != s.end()){
      count++;
      s.erase({i->first + 0, i->second + 2018});
    }
    else if (s.find({i->first + 0, i->second - 2018}) != s.end()){
      count++;
      s.erase({i->first + 0, i->second - 2018});
    }
    else if (s.find({i->first + 1118, i->second + 1680}) != s.end()){
      count++;
      s.erase({i->first + 1118, i->second + 1680});
    }
    else if (s.find({i->first + 1118, i->second - 1680}) != s.end()){
      count++;
      s.erase({i->first + 1118, i->second - 1680});
    }
    // else if (s.find({i->first - 1118, i->second + 1680}) != s.end()){
    //   count++;
    //   s.erase({i->first - 1118, i->second + 1680});
    // }
    // else if (s.find({i->first - 1118, i->second - 1680}) != s.end()){
    //   count++;
    //   s.erase({i->first - 1118, i->second - 1680});
    // }
    else if (s.find({i->first + 1680, i->second + 1118}) != s.end()){
      count++;
      s.erase({i->first + 1680, i->second + 1118});
    }
    else if (s.find({i->first + 1680, i->second - 1118}) != s.end()){
      count++;
      s.erase({i->first + 1680, i->second - 1118});
    }
    // else if (s.find({i->first - 1680, i->second + 1118}) != s.end()){
    //   count++;
    //   s.erase({i->first - 1680, i->second + 1118});
    // }
    // else if (s.find({i->first - 1680, i->second - 1118}) != s.end()){
    //   count++;
    //   s.erase({i->first - 1680, i->second - 1118});
    // }
    else if (s.find({i->first + 2018, i->second + 0}) != s.end()){
      count++;
      s.erase({i->first + 2018, i->second + 0});
    }
    // else if (s.find({i->first - 2018, i->second + 0}) != s.end()){
    //   count++;
    //   s.erase({i->first - 2018, i->second + 0});
    // }
  }
  cout << count << endl;
}
