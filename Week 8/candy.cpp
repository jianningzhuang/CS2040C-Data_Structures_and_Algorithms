#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ll n;
  cin >> n;
  set<ll> s;
  for (int i = 0; i < sqrt(n) + 1; i++){
    if (n%(i+1) == 0){
      s.insert(i);
      cout << i << " ";
    }
  }
  for (auto i = s.rbegin(); i != s.rend(); i++){
    ll temp = n/(*i+1) - 1;
    if (s.find(temp) == s.end()){
      cout << temp << " ";
    }
  }
}
