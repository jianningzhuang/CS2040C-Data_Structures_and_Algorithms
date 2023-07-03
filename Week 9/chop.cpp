#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> pq;
  for (int i = 1; i <= n + 1; i++){
    pq.insert(i);
  }
  queue<int> chop;
  for (int i = 0; i < n; i++){
    int v;
    cin >> v;
    pq.erase(v);
    chop.push(v);
  }
  vector<int> order;
  while (!chop.empty()){
    int curr = chop.front();
    if (*(pq.begin()) > curr){
      cout << "Error\n";
      return 0;
    }
    else{
      order.push_back(*(pq.begin()));
      pq.erase(pq.begin());
      pq.insert(curr);
      chop.pop();
    }
  }
  for (auto it = order.begin(); it !=  order.end(); it++){
    cout << *it << endl;
  }
}
