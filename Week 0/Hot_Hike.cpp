#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int vacation[n];
  for (int i = 0; i < n; i++){
    cin >> vacation[i];
  }
  int minimax = 41;
  int best_day = 0;
  for (int j = 0; j < n - 2; j++){
    if (vacation[j] >= vacation[j+2]){
      if (vacation[j] < minimax){
        minimax = vacation[j];
        best_day = j;
      }
    }
    else{
      if (vacation[j+2] < minimax){
        minimax = vacation[j+2];
        best_day = j;
      }
    }
  }
  cout << best_day + 1 << " " << minimax;
}
