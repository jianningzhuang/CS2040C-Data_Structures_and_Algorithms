#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while (cin >> n){
    stack<int> s;
    priority_queue<int> pq;
    queue<int> q;
    bool ys = true;
    bool yp = true;
    bool yq = true;
    for (int i = 0; i < n; i++){
      int type, x;
      cin >> type >> x;
      if (type == 1){
        s.push(x);
        pq.push(x);
        q.push(x);
      }
      if (type == 2){
        if (s.empty() || s.top() != x){
          ys = false;
        }
        if (pq.empty() || pq.top() != x){
          yp = false;
        }
        if (q.empty() || q.front() != x){
          yq = false;
        }
        if (!s.empty()){
          s.pop();
        }
        if (!pq.empty()){
          pq.pop();
        }
        if (!q.empty()){
          q.pop();
        }
      }
    }
    if (ys && !yp && !yq){
      cout << "stack\n";
    }
    else if (yp && !ys && !yq){
      cout << "priority queue\n";
    }
    else if (yq && !ys && !yp){
      cout << "queue\n";
    }
    else if (!yp && !ys && !yq){
      cout << "impossible\n";
    }
    else{
      cout << "not sure\n";
    }
  }
}
