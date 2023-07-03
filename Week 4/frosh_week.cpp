#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int binary_position(ll a[], ll value, int low, int high){
  if (high <= low){
    if (value > a[low]){
      return low + 1;
    }
    else{
      return low;
    }
  }
  int mid = (low + high)/2;
  if (value == a[mid]){
    return mid + 1;
  }
  else if (value > a[mid]){
    return binary_position(a, value, mid+1, high);
  }
  else{
    return binary_position(a, value, low, mid - 1);
  }
}

int main(){
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    a[i] = temp;
  }
  int swaps = 0;
  for (int i = 1; i < n; i++){
    int pos = binary_position(a, a[i], 0, i - 1);
    swaps += (i - pos);
    ll temp = a[pos];
    a[pos] = a[i];
    a[i] = temp;
  }
  cout << swaps;
}
