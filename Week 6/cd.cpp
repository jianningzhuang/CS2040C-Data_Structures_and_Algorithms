#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  while (n != 0 && m != 0){
    unordered_set<int> s;
    for (int i = 0; i < n; i++){
      int disk;
      cin >> disk;
      s.insert(disk);
    }
    int count = 0;
    for (int i = 0; i < m; i++){
      int disk;
      cin >> disk;
      if (s.find(disk) != s.end()){
        count++;
      }
    }
    cout << count << endl;
    cin >> n >> m;
  }
  return 0;
}
