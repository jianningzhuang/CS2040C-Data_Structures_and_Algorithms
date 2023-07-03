#include <iostream>
using namespace std;

int main(){
  int n1;
  cin >> n1;
  int n2;
  cin >> n2;
  int difference = n2 - n1;
  if (difference <= 180 && difference > -180){
    cout << difference << "\n";
  }
  else{
    if (difference > 180){
      cout << difference - 360 << "\n";
    }
    else{
      cout << difference + 360 << "\n";
    }
  }
}
