#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  deque<ll> t;
  int size = 0;
  for (int i = 0; i < N; i++){
    string command;
    ll val;
    cin >> command >> val;
    if (command == "push_back"){
      t.push_back(val);
      size++;
    }
    else if (command == "push_front"){
      t.push_front(val);
      size++;
    }
    else if (command == "push_middle"){
      int index;
      index = (size+1)/2;
      deque<ll>::iterator it = t.begin();
      advance(it, index);
      t.insert(it, val);
      size++;
    }
    else if (command == "get"){
      cout << t[val] << endl;
    }
  }
}
