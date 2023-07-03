#include <bits/stdc++.h>
using namespace std;

bool subseq(vector<int> a, vector<int> b){
  int i = 0;
  int j = 0;
  while (i < a.size() && j < b.size()){
    if (a[i] == b[j]){
      i++;
      j++;
    }
    else{
      i++;
    }
  }
  return (j == b.size());
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> seq;
  for (int i = 0; i < m; i++){
    int g;
    cin >> g;
    seq.push_back(g);
  }
  vector<int> perm;
  for (int i = 0; i < n; i++){
    perm.push_back(i+1);
  }
  while (true){
    if (subseq(perm, seq)){
      for (int k = 0; k < n; k++){
        cout << perm[k] << endl;
      }
      return 0;
    }
    else{
      next_permutation(perm.begin(), perm.end());
    }
  }
}
