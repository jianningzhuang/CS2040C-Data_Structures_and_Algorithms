#include <bits/stdc++.h>
using namespace std;

int main(){
  int r, n;
  cin >> r >> n;
  vector<bool> hotel(r);
  for (int i = 0; i < n; i++){
    int booked;
    cin >> booked;
    hotel[booked - 1] = true;
  }
  for (int i = 0; i < r; i++){
    if (hotel[i] == false){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << "too late\n";
}
