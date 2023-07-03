#include <iostream>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  if (M >= N){
    if (M-N == 1){
      cout << "Dr. Chaz will have " << M-N << " piece of chicken left over!\n";
    }
    else{
      cout << "Dr. Chaz will have " << M-N << " pieces of chicken left over!\n";
    }
  }
  else{
    if (N-M == 1){
      cout << "Dr. Chaz needs " << N-M << " more piece of chicken!\n";
    }
    else{
      cout << "Dr. Chaz needs " << N-M << " more pieces of chicken!\n";
    }
  }
}
