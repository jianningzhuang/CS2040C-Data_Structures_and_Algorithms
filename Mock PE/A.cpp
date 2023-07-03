#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  set<int> s;
  queue<int> q;
  for (int i = 1; i <= n; i++){
    s.insert(i);
  }
  for (int i = 0; i < m; i++){
    int g;
    cin >> g;
    q.push(g);
    s.erase(g);
  }
  for (int i = 0; i < n; i++){
    if (s.empty()){
      cout << q.front() << endl;
      q.pop();
    }
    else if (q.empty()){
      cout << *(s.begin()) << endl;
      s.erase(s.begin());
    }
    else if (*(s.begin()) < q.front()){
      cout << *(s.begin()) << endl;
      s.erase(s.begin());
    }
    else{
      cout << q.front() << endl;
      q.pop();
    }
  }
}
