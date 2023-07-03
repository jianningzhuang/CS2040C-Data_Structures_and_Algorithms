#include <bits/stdc++.h>
using namespace std;

int main(){
  long long counter = 0;
  clock_t begin = clock();
  int N = 10000;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      counter++;
    }
  }
  cout << fixed << setprecision(12) << (double)(clock()-begin)/CLOCKS_PER_SEC;
}
