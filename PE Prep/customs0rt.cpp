#include <bits/stdc++.h>
using namespace std;



bool compare(pair<int, string> p1, pair<int, string> p2){
  if (p1.first == p2.first){
    return lexicographical_compare(p1.second.begin(), p1.second.end(), p2.second.begin(), p2.second.end());
  }
  else{
    return p1.first < p2.first;
  }
}

int main(){
  vector<pair<int, string>> pq;
  vector<int> p;
  p.push_back(1);
  p.push_back(2);
  sort(p.begin(), p.end());
  cout << p.front() << endl;
  pq.push_back({1,"a"});
  pq.push_back({2,"a"});
  pq.push_back({1, "b"});
  sort(pq.begin(), pq.end(), compare);
  cout << pq.front().second << endl;
}
