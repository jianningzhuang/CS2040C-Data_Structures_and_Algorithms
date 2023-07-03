#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

struct Vertex{
  ll item;
  Vertex* next;
  Vertex* prev;
};

class Teque{
private:
  Vertex* head;
  Vertex* tail;
  int size;
public:
  Teque(){
    head = NULL;
    tail = head;
    size = 0;
  }
  Vertex* get(int i){
    Vertex* ptr = head;
    for (int j = 0; j < i; j++){
      ptr = ptr->next;
    }
    return ptr;
  }
  void push_empty(ll value){
    Vertex* vtx = new Vertex();
    vtx->item = value;
    vtx->next = head;
    head = vtx;
    tail = head;
    size++;
  }
  void push_front(ll value){
    if (head == NULL){
      push_empty(value);
      return;
    }
    Vertex* vtx = new Vertex();
    vtx->item = value;
    vtx->next = head;
    head->prev = vtx;
    head = vtx;
    size++;
  }
  void push_back(ll value){
    if (head == NULL){
      push_empty(value);
      return;
    }
    Vertex* vtx = new Vertex();
    vtx->item = value;
    tail->next = vtx;
    vtx->prev = tail;
    tail = vtx;
    size++;
  }
  void push_middle(ll value){
    if (head == NULL){
      push_empty(value);
      return;
    }
    else if (size == 1){
      push_back(value);
      return;
    }
    else{
      Vertex* vtx = new Vertex();
      vtx->item = value;
      int index;
      index = (size+1)/2;
      Vertex* pre = get(index - 1);
      Vertex* aft = pre->next;
      pre->next = vtx;
      vtx->prev = pre;
      vtx->next = aft;
      aft->prev = vtx;
      size++;
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  Teque t;
  for (int i = 0; i < N; i++){
    string command;
    ll val;
    cin >> command >> val;
    if (command == "push_back"){
      t.push_back(val);
    }
    else if (command == "push_front"){
      t.push_front(val);
    }
    else if (command == "push_middle"){
      t.push_middle(val);
    }
    else if (command == "get"){
      cout << (t.get(val))->item << endl;
    }
  }
}
