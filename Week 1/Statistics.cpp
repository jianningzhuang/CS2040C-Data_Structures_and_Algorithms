#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int counter = 1;
  int n;
  while (cin >> n){
    vector<int> v;
    for (int i = 0; i < n; i++){
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << "Case " << counter << ": " << v[0] << " " << v[n-1] << " " << v[n-1] - v[0] << "\n";
    counter++;
  }
}

// int main(){
//   int counter = 1;
//   int n;
//   while (cin >> n){
//     int min;
//     int max;
//     cin >> min;
//     max = min;
//     for (int i = 0; i < n-1; i++){
//       int next;
//       cin >> next;
//       if (next < min){
//         min = next;
//       }
//       if (next > max){
//         max = next;
//       }
//     }
//     cout << "Case " << counter << ": " << min << " " << max << " " << max-min << endl;
//     counter++;
//   }
// }
