#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int n;
  cin >> n;
  deque<ll>s1;
  stack<ll>s2;
  for (int i = 0; i < 2*n; i++){
    ll temp;
    cin >> temp;
    s1.push_back(temp);
  }
  ll count = 0;
  bool paired = false;
  int direction = 1;
  while (true){
    paired = false;
    if (s1.empty() && s2.empty()){
      break;
    }
    if (direction == 1){
      while (!s1.empty()){
        count++;
        if (s2.empty()){
          s2.push(s1.front());
          s1.pop_front();
        }
        else if (s1.front() == s2.top()){
          s1.pop_front();
          s2.pop();
          paired = true;
        }
        else{
          s2.push(s1.front());
          s1.pop_front();
        }
      }
      if (paired){
        direction = 0;
      }
      else{
        cout << "impossible\n";
        return 0;
      }
    }
    else{
      while (!s2.empty()){
        count++;
        if (s1.empty()){
          s1.push_front(s2.top());
          s2.pop();
        }
        else if (s1.front() == s2.top()){
          s1.pop_front();
          s2.pop();
          paired = true;
        }
        else{
          s1.push_front(s2.top());
          s2.pop();
        }
      }
      if (paired){
        direction = 1;
      }
      else{
        cout << "impossible\n";
        return 0;
      }
    }
  }
  cout << count;
}
