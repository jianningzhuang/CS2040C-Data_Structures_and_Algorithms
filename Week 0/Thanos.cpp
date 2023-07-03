#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  cin >> n;
  while (n > 0){
    long long p, r, f;
    cin >> p >> r >> f;
    long long years = 0;
    while (p <= f){
      p *= r;
      years++;
    }
    cout << years << "\n";
    n--;
  }
}
