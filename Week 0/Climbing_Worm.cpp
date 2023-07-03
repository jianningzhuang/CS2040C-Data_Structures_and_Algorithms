#include <iostream>
using namespace std;

int main(){
  int a, b, h;
  cin >> a >> b >> h;
  int progress = 0;
  int counter = 0;
  while (true){
    progress += a;
    counter += 1;
    if (progress >= h){
      break;
    }
    else{
      progress -= b;
    }
  }
  cout << counter;
}
