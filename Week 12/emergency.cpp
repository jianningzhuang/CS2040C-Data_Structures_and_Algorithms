#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ll n, k;
  cin >> n >> k;
  if (n <= 2*k){
    cout << n - 1 << endl;
  }
  else{
    cout << k + (n-1)%k + 1 << endl;
  }
}
