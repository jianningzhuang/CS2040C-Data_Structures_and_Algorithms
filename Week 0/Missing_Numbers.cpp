#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int current = 1;
  for (int i = 0; i < n; i++){
    int num;
    cin >> num;
    if (i == n - 1 && num == n){
      cout << "good job\n";
    }
    for (int j = current; j < num; j++){
      cout << j << "\n";
    }
    current = num + 1;
  }

}
