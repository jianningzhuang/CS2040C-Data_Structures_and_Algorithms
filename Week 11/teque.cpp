#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  deque<int> q1;
  deque<int> q2;
  int l = 0;
  int r = 0;
  for (int i = 0; i < n; i++){
    string cmd;
    int x;
    cin >> cmd >> x;
    if (cmd == "push_back"){
      q2.push_back(x);
      r++;
      if (r-l == 2){
        q1.push_back(q2.front());
        q2.pop_front();
        r--;
        l++;
      }
    }
    else if (cmd == "push_front"){
      q1.push_front(x);
      l++;
      if (l-r == 2){
        q2.push_front(q1.back());
        q1.pop_back();
        l--;
        r++;
      }
    }
    else if (cmd == "push_middle"){
      if (l == r){
        q1.push_back(x);
        l++;
      }
      else if (l > r){
        q2.push_front(x);
        r++;
      }
      else if (r > l){
        q1.push_back(q2.front());
        q2.pop_front();
        q2.push_front(x);
        l++;
      }
    }
    else if (cmd == "get"){
      if (x >= l){
        cout << q2[x - l] << endl;
      }
      else{
        cout << q1[x] << endl;
      }
    }
  }
}
