#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

void counting_sort(ll a[], int n, ll exp, ll base){
  ll result[n];
  int bucket[base] = {0};
  for (int i = 0; i < n; ++i)
    bucket[(a[i] / exp) & (base - 1)]++;
  for (int i = 1; i < base; ++i)
    bucket[i] += bucket[i-1];
  for (int i = n-1; i >= 0; --i){
    result[bucket[(a[i] / exp) & (base - 1)] - 1] = a[i];
    bucket[(a[i] / exp) & (base - 1)]--;
  }
  for (int i = 0; i < n; i++){
    a[i] = result[i];
  }
}

void radix_sort(ll a[], int n, ll max, ll base){
  for (ll exp = 1; max/exp > 0; exp *= base)
    counting_sort(a, n, exp, base);
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
    ll s[n];
    s[0] = a;
    for (int j = 1; j < n; ++j){
      s[j] = (s[j - 1]*b + a)%c;
    }
    cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC << endl;
    // int base = 1;
    // while (n > base){
    //   base = base << 1;
    // }
    // base = base >> 1;
    if (c < a){
      s[0] = c;
      radix_sort(s, n, c, 65536);
      s[n-1] = a;
    }
    else{
      radix_sort(s, n, c, 65536);
    }
    ll v = 0;
    for (int k = 0; k < n; ++k){
      v = (v*x + s[k])%y;
    }
    cout << v << endl;
    cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC << endl;
  }
}
