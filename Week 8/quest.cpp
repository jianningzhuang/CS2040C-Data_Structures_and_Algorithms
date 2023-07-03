#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int n;
  cin >> n;
  map<int, priority_queue<int>> pool;
  for (int i = 0; i < n; i++){
    string cmd;
    cin >> cmd;
    if (cmd == "add"){
      int e, g;
      cin >> e >> g;
      pool[e].push(g);
    }
    else if (cmd == "query"){
      int energy;
      cin >> energy;
      ll total = 0;
      while (energy){
        auto it = pool.upper_bound(energy);
        if (it == pool.begin()){
          break;
        }
        it--;
        energy -= it->first;
        priority_queue<int> &pq = it->second;
        total += pq.top();
        pq.pop();
        if (pq.empty()){
          pool.erase(it);
        }
      }
      cout << total << endl;
    }
  }
}
