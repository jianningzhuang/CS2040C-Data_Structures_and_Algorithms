#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  deque<ll> left;
  deque<ll> right;
  int l = 0;
  int r = 0;
  for (int i = 0; i < N; i++){
    string command;
    ll val;
    cin >> command >> val;
    if (command == "push_back"){
      right.push_back(val);
      r++;
      if (r - l == 2){
        ll temp = right.front();
        left.push_back(temp);
        right.pop_front();
        r--;
        l++;
      }
    }
    else if (command == "push_front"){
      left.push_front(val);
      l++;
      if (l - r == 2){
        ll temp = left.back();
        right.push_front(temp);
        left.pop_back();
        l--;
        r++;
      }
    }
    else if (command == "push_middle"){
      if (l == r){
        left.push_back(val);
        l++;
      }
      else if (l > r){
        right.push_front(val);
        r++;
      }
      else if (r > l){
        ll temp = right.front();
        left.push_back(temp);
        right.pop_front();
        right.push_front(val);
        l++;
      }
    }
    else if (command == "get"){
      if (val < l){
        cout << left[val] << endl;
      }
      else{
        cout << right[val - l] << endl;
      }
    }
  }
}
