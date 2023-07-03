#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int n, b;
  cin >> n >> b;
  vector<int> v;
  int med;
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    v.push_back(a);
    if (a == b){
      med = i;
    }
  }
  map<int, int> m;
  m[0] = 1;
  int greater = 0;
  for (int i = med + 1; i < n; i++){
    if (v[i] > b){
      greater++;
    }
    else{
      greater--;
    }
    m[greater]++;
  }

  ll result = m[0];
  greater = 0;
  for (int i = med - 1; i >= 0; i--){
    if (v[i] > b){
      greater--;
    }
    else{
      greater++;
    }
    result += m[greater];
  }
  cout << result << endl;
}
