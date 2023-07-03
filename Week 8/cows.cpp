#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int c, n, m;
  cin >> c >> n >> m;
  vector<int> v;
  ll doubling = 0;
  int original = 0;
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    v.push_back(temp);
    if (temp*2 > c){
      doubling++;
      original++;
    }
  }
  ll cc = n;
  vector<ll> days;
  days.push_back(cc);
  for (int i = 0; i <= 50; i++){
    int current = 0;
    for (int j = 0; j < n; j++){
      if (v[j]*2 > c){
        current++;
      }
      else{
        v[j] = v[j]*2;
      }
    }
    cc += doubling;
    cc += (current - original);
    days.push_back(cc);
    doubling += (current - original);
    doubling *= 2;
    // doubling += (current - original);
    original = current;
  }
  for (int i = 0; i < m; i++){
    int d;
    cin >> d;
    cout << days[d] << endl;
  }
}
