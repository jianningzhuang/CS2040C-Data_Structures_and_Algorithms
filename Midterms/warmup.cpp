#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

//3:14 to 3:28 firsst try

int main(){
  int n;
  cin >> n;
  stack<ll> s1;
  stack<ll> s2;
  for (int i = 0; i < 2*n; i++){
    ll temp;
    cin >> temp;
    s1.push(temp);
  }
  ll moves = 0;
  int forward = 1;
  while (true){
    bool paired = false;
    if (forward == 1){
      while (!s1.empty()){
        if (s2.empty() || s2.top() != s1.top()){
          s2.push(s1.top());
          s1.pop();
          moves++;
        }
        else if (s1.top() == s2.top()){
          s2.pop();
          s1.pop();
          moves++;
          paired = true;
        }
      }
      if (s1.empty() && s2.empty()){
        cout << moves << endl;
        return 0;
      }
      else if (paired){
        forward--;
        continue;
      }
      else{
        cout << "impossible\n";
        return 0;
      }
    }
    else if (forward == 0){
      while (!s2.empty()){
        if (s1.empty() || s2.top() != s1.top()){
          s1.push(s2.top());
          s2.pop();
          moves++;
        }
        else if (s1.top() == s2.top()){
          s2.pop();
          s1.pop();
          moves++;
          paired = true;
        }
      }
      if (s1.empty() && s2.empty()){
        cout << moves << endl;
        return 0;
      }
      else if (paired){
        forward++;
        continue;
      }
      else{
        cout << "impossible\n";
        return 0;
      }
    }
  }

}
