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
  Vertex* mid;
  int count;
  int size;
public:
  Teque(){
    head = NULL;
    tail = head;
    mid = head;
    count = 0;
    size = 0;
  }
  Vertex* get(int i){
    Vertex* ptr;
    if (i>size/2){
      ptr = tail;
      for (int j = size - 1; j > i; j--){
        ptr = ptr->prev;
      }
    }
    else{
      ptr = head;
      for (int j = 0; j < i; j++){
        ptr = ptr->next;
      }
    }
    return ptr;
  }
  void push_empty(ll value){
    Vertex* vtx = new Vertex();
    vtx->item = value;
    vtx->next = head;
    head = vtx;
    tail = head;
    mid = head;
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
    count--;
    if (count == -2){
      mid = mid->prev;
      count = 0;
    }
    size++;
    if (size == 3){
      mid = head->next;
      count = 0;
    }
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
    count++;
    if (count == 2){
      mid = mid->next;
      count = 0;
    }
    size++;
    if (size == 3){
      mid = head->next;
      count = 0;
    }
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
    else if (size == 2){
      Vertex* vtx = new Vertex();
      vtx->item = value;
      head->next = vtx;
      vtx->prev = head;
      vtx->next = tail;
      tail->prev = vtx;
      mid = vtx;
      count = 0;
      size++;
    }
    else{
      Vertex* vtx = new Vertex();
      vtx->item = value;
      if (count > 0){
        Vertex* temp = mid->next;
        mid->next = vtx;
        vtx->prev = mid;
        vtx->next = temp;
        temp->prev = vtx;
        mid = vtx;
        count = 0;
      }
      else if (count < 0){
        Vertex* temp = mid->prev;
        temp->next = vtx;
        vtx->prev = temp;
        vtx->next = mid;
        mid->prev = vtx;
        mid = vtx;
        count = 0;
      }
      else{
        Vertex* temp = mid->next;
        mid->next = vtx;
        vtx->prev = mid;
        vtx->next = temp;
        temp->prev = vtx;
        count = 1;
      }
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
