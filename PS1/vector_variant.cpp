#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;


void counting_sort(vector<ll> &v, int n, ll exp){
  vector<ll> result(n);
  vector<int> bucket(n);
  for (int i = 0; i < n; ++i)
    ++bucket[(v[i] / exp) % n];
  for (int i = 1; i < n; ++i)
    bucket[i] += bucket[i-1];
  for (int i = n-1; i >= 0; --i){
    result[bucket[(v[i] / exp) % n]-- - 1] = v[i];
  }
  v = result;
}

void radix_sort(vector<ll> &v, int n, ll max){
  //clock_t begin = clock();
  for (ll exp = 1; max/exp > 0; exp *= n)
    counting_sort(v, n, exp);
    //cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC << endl;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i){
    int n;
    ll a, b, c, x, y;
    cin >> n >> a >> b >> c >> x >> y;
    clock_t begin = clock();
    vector<ll> s(n);
    s[0] = a;
    for (int j = 1; j < n; ++j){
      s[j] = (s[j - 1]*b + a)% c;
    }
    cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC << endl;
    if (n < 32768){
      sort(s.begin(), s.end());
    }
    else if (c < a){
      s[0] = c;
      radix_sort(s, n, c);
      s[n-1] = a;
    }
    else{
      radix_sort(s, n, c);
    }
    ll v = 0;
    for (int k = 0; k < n; ++k){
      v = (v*x + s[k])%y;
    }
    cout << v << endl;
    cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC << endl;
  }
}
