#include <iostream>
#include <vector>
#include <set>
using namespace std;

class year{
private:
  vector<bool> days;
public:
  year(){
    days.assign(366, false);
  }
  void confirm(int s, int t){
    for (int i = s; i <= t; i++){
      days[i] = true;
    }
  }
  int count(){
    int result = 0;
    for (int i = 1; i <= 365; i++){
      if (days[i]){
        result++;
      }
    }
    return result;
  }
};

int main(){
  set<int> days;
  int N;
  year y;
  cin >> N;
  for (int i = 0; i < N; i++){
    int s, t;
    cin >> s >> t;
    y.confirm(s, t);
    // for (int j = s; j <= t; j++){
    //   days.insert(j);
    // }
  }
  cout << y.count();
//  cout << days.size();

}

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   int N; cin >> N;
//   vector<bool> got_ff(366, false);
//   while (N--) {
//     int s, t; cin >> s >> t;
//     for (int i = s; i <= t; ++i)
//       got_ff[i] = true;
//   }
//   int ans = 0;
//   for (int i = 1; i <= 365; ++i)
//     if (got_ff[i])
//       ++ans;
//   cout << ans << "\n";
//   return 0;
// }
