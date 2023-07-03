#include <iostream>
using namespace std;

struct Vertex{
  int item;  //data stored
  Vertex *next; //pointer to next vertex
};

Vertex *get(int n){  //returns vertex at index n
  Vertex *ptr = head;  //start from head
  for (int i = 0; i < n; i++){ //advance pointer n times
    ptr = ptr->next;
  }
  return ptr;  //O(n) compared to array access O(1)
}

int search(int target){
  int index = 0;
  Vertex *ptr = head;
  while (ptr != tail){
    if (ptr->item == target){
      return index;
    }
    index++;
    ptr = ptr->next;

  }
  if (ptr->item == target){
    return index;
  }
  return -1;
}
