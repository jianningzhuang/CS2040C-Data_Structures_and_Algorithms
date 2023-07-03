#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int d, m;
    int result = 0;
    int current = 0;
    cin >> d >> m;
    for (int j = 0; j < m; j++){
      int days;
      cin >> days;
      if (days < 13){
        current += days;
      }
      else{
        current += 12;
        if (current%7 == 5){
          result++;
        }
        current += (days - 12);
      }
    }
    cout << result << endl;
  }
}
