#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ll m, n, t;
  cin >> m >> n >> t;
  if (t == 1){
    ll fact = 1;
    for (int i = n; i > 0; i--){
      fact *= i;
      if (fact > m){
        cout << "TLE\n";
        return 0;
      }
    }
    cout << "AC\n";
  }
  else if (t == 2){
    ll power = 1;
    for (int i = 0; i < n; i++){
      power *= 2;
      if (power > m){
        cout << "TLE\n";
        return 0;
      }
    }
    cout << "AC\n";
  }
  else if (t == 3){
    ll product = 1;
    for (int i = 0; i < 4; i++){
      product *= n;
      if (product > m){
        cout << "TLE\n";
        return 0;
      }
    }
    cout << "AC\n";
  }
  else if (t == 4){
    ll product = 1;
    for (int i = 0; i < 3; i++){
      product *= n;
      if (product > m){
        cout << "TLE\n";
        return 0;
      }
    }
    cout << "AC\n";
  }
  else if (t == 5){
    ll product = 1;
    for (int i = 0; i < 2; i++){
      product *= n;
      if (product > m){
        cout << "TLE\n";
        return 0;
      }
    }
    cout << "AC\n";
  }
  else if (t == 6){
    if (log2(n)*n > m){
      cout << "TLE\n";
      return 0;
    }
    cout << "AC\n";
  }
  else if (t == 7){
    ll product = 1;
    for (int i = 0; i < 1; i++){
      product *= n;
      if (product > m){
        cout << "TLE\n";
        return 0;
      }
    }
    cout << "AC\n";
  }
}
