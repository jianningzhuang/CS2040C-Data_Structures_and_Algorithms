#include <bits/stdc++.h>
using namespace std;

//start 447 to

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int n, t, m;
    cin >> n >> t >> m;
    queue<int> left;
    queue<int> right;
    for (int j = 0; j < m; j++){
      int time;
      string bank;
      cin >> time >> bank;
      if (bank == "left"){
        left.push(time);
      }
      else{
        right.push(time);
      }
    }
    int curr = 0;
    bool side = true;
    while (!left.empty() || !right.empty()){
      int ferry = 0;
      if (side){
        if (left.front() > curr && right.front() > curr){
          if (left.front() <= right.front()){
            curr = left.front();
          }
          else{
            curr = right.front() + t;
            side = false;
            continue;
          }
        }
        for (int a = 0; a < n; a++){
          if (!left.empty() && left.front() <= curr){
            ferry++;
            left.pop();
          }
          else{
            break;
          }
        }
        curr += t;
        side = false;
        for (int b = 0; b < ferry; b++){
          cout << curr << endl;
        }
      }
      else{
        if (left.front() > curr && right.front() > curr){
          if (right.front() <= left.front()){
            curr = right.front();
          }
          else{
            curr = left.front() + t;
            side = true;
            continue;
          }
        }
        for (int a = 0; a < n; a++){
          if (!right.empty() && right.front() <= curr){
            ferry++;
            right.pop();
          }
          else{
            break;
          }
        }
        curr += t;
        side = true;
        for (int b = 0; b < ferry; b++){
          cout << curr << endl;
        }
      }
    }
  }
}
