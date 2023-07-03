#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int g;
    cin >> g;
    unordered_set<ll> s;
    for (int j = 0; j < g; j++){
      ll num;
      cin >> num;
      if (s.find(num) != s.end()){
        s.erase(num);
      }
      else{
        s.insert(num);
      }
    }
    cout << "Case #" << i+1 << ": " << *(s.begin()) << endl;
  }
}
