#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<long long> &v){
  for (auto i = v.begin(); i != v.end(); i++){
    cout << *i << " ";
  }
  cout << endl;
}

void bucket_sort(vector<long long> &v, int size, long long c){
  vector<long long> b[c];
  for (int i = 0; i < size; i++){
    b[v[i]].push_back(v[i]);
  }
  for (int i = 0; i < size; i++){
    sort(b[i].begin(), b[i].end());
  }
  int index = 0;
  for (int i = 0; i < size; i++){
    for (int j = 0; j < b[i].size(); j++){
      v[index] = b[i][j];
      index++;
    }
  }
}

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int n;
    long long a, b, c, x, y;
    cin >> n >> a >> b >> c >> x >> y;
    clock_t begin = clock();
    vector<long long> s;
    s.push_back(a);
    for (int j = 1; j < n; j++){
      long long temp = (s[j - 1]*b + a)% c;
      s.push_back(temp);
    }
    cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC << endl;
    if (a > c){
      s[0] = s[n-1];
      s.pop_back();
      bucket_sort(s, n - 1, c);
      s.push_back(a);
    }
    else{
      bucket_sort(s, n, c);
    }
    long long v = 0;
    for (int k = 0; k < n; k++){
      long long temp = (v*x + s[k])%y;
      v = temp;
    }
    cout << v << endl;
    cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC << endl;
  }
}
