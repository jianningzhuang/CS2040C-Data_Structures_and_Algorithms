#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int min[n];
  int max[n];
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    a[i] = temp;
  }
  max[0] = a[0];
  for (int i = 1; i < n; i++){
    if (a[i] > max[i-1]){
      max[i] = a[i];
    }
    else{
      max[i] = max[i-1];
    }
  }
  min[n-1] = a[n-1];
  for (int i = n - 2; i >= 0; i--){
    if (a[i] < min[i + 1]){
      min[i] = a[i];
    }
    else{
      min[i] = min[i+1];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++){
    if (a[i] >= max[i] && a[i] <= min[i]){
      count++;
    }
  }
  cout << count;
}
