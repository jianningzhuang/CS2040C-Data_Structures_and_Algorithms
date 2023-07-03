#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<bool> v(1005);
  for (int i = 0; i < n; i++){
    int bus;
    cin >> bus;
    v[bus] = true;
  }
  int streak = 0;
  int start = 0;
  for (int i = 1; i < 1005; i++){
    if (v[i] == true){
      streak++;
      if (streak == 1){
        start = i;
      }
    }
    if (v[i] == false && streak > 0){
      if (streak == 1){
        cout << start << " ";
        streak = 0;
      }
      else if (streak == 2){
        cout << start << " " << start + 1 << " ";
        streak = 0;
      }
      else{
        cout << start << "-" << i - 1 << " ";
        streak = 0;
      }
    }
  }
}
