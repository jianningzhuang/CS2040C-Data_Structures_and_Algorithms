#include <bits/stdc++.h>
using namespace std;

//using sets to find lower and upper bound

typedef unsigned long long ll;

int main(){
  int n;
  cin >> n;
  map<int, int> s;
  ll counter = 0;
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    if (s.empty()){
      s[temp] = 0;
    }
    else{
      int l = 0;
      int r = 0;
      if (s.lower_bound(temp - 1) != s.end()){
        l = s.lower_bound(temp - 1)->second;
      }
      auto it = s.upper_bound(temp + 1);
      it--;
      if (it != s.end()){
        r = it->second;
      }
      int d = max(l, r) + 1;
      s[temp] = d;
      counter += d;
    }
    cout << counter << endl;
  }

}
