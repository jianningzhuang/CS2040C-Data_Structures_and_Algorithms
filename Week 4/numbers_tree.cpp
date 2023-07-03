#include <bits/stdc++.h>
using namespace std;

int main(){
  int h;
  string path;
  cin >> h >> path;
  int root = 1;
  for (int i = 0; i <= h; i++){
    root *= 2;
  }
  int index = 1;
  for (auto &c : path){
    if (c == 'L'){
      index *= 2;
    }
    else{
      index *= 2;
      index++;
    }
  }
  cout << root - index;

}
