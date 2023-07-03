#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

pair<ll, ll> fraction(ll index){
  pair<ll, ll> p;
  if (index == 1 || index == 0){
    return {1,1};
  }
  else{
    pair<ll, ll> parent = fraction(index/2);
    if (index%2 == 0){
      p.first = parent.first;
      p.second = parent.first + parent.second;
    }
    else{
      p.first = parent.first + parent.second;
      p.second = parent.second;
    }
    return p;
  }
}

int main(){
  int p;
  cin >> p;
  for (int i = 0; i < p; i++){
    ll k, index;
    cin >> k >> index;
    pair<ll, ll> p = fraction(index);
    cout << k << " " << p.first << "/" << p.second << endl;
  }
}
