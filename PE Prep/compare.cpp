#include <bits/stdc++.h>
using namespace std;

struct compare{  //largest int first, smallest lexi if same
  bool operator()(pair<int, string> p1, pair<int, string> p2){
    if (p1.first == p2.first){
      return lexicographical_compare(p2.second.begin(), p2.second.end(), p1.second.begin(), p1.second.end());
    }
    else{
      return p1.first > p2.first;
    }
  }
};

int main(){
  priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
  priority_queue<int> p;
  p.push(1);
  p.push(2);
  cout << p.top() << endl;
  pq.push({1,"a"});
  pq.push({2,"a"});
  pq.push({1, "b"});
  pq.push({2, "b"});
  cout << pq.top().first << pq.top().second << endl;
}
