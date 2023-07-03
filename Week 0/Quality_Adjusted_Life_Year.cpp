#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int n;
  cin >> n;
  double result = 0;
  for (int i = 0; i < n; i++){
    double q, y;
    cin >> q >> y;
    result += q*y;
  }
  cout << fixed << setprecision(3) << result;
}
