#include <bits/stdc++.h>
using namespace std;

bool equal(string arr[], string temp[], int len){
  for (int i = 0; i < len; i++){
    if (arr[i] != temp[i]){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  string arr[n];
  string inc[n];
  string dec[n];
  for (int i = 0; i < n; i++){
    string name;
    cin >> name;
    arr[i] = name;
    inc[i] = name;
    dec[i] = name;
  }
  sort(inc, inc + n);
  sort(dec, dec + n, greater<string>());
  if (equal(arr, inc, n)){
    cout << "INCREASING" << endl;
  }
  else if (equal(arr, dec, n)){
    cout << "DECREASING" << endl;
  }
  else{
    cout << "NEITHER" << endl;
  }
}
