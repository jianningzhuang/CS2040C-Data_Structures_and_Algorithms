#include <bits/stdc++.h>
using namespace std;

class Queue{
private:
  vector<int> s1;
  vector<int> s2;
public:
  void enqueue(int val){
    s1.push_back(val);
  }
  void dequeue(){
    if (s2.empty()){
      while (!s1.empty()){
        s2.push_back(s1.back());
        s1.pop_back();
      }
    }
    cout << s2.back() << endl;
    s2.pop_back();
  }
};

int main(){
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(2);
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
}
