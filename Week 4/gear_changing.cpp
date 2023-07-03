#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int len){
  for (int i = 0; i < len; i++){
    cout << arr[i] << " ";
  }
}

int main(){
  int n, m, p;
  cin >> n >> m >> p;
  int crank[n];
  for (int i = 0; i < n; i++){
    int c;
    cin >> c;
    crank[i] = c;
  }
  //print_arr(crank, n);
  int back[m];
  for (int i = 0; i < m; i++){
    int d;
    cin >> d;
    back[i] = d;
  }
  //print_arr(back, m);
  vector<double> f;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      f.push_back(double(crank[i])/(back[j]));
    }
  }
  sort(f.begin(), f.end());
  for (int i = 0; i < n*m; i++){
    cout << f[i] << " ";
  }
  for (int i = 0; i < n*m - 1; i++){
    if (f[i+1] - f[i] > double(p)/100){
      cout << "Time to change gears!" << endl;
      return 0;
    }
  }
  cout << "Ride on!\n";

}
