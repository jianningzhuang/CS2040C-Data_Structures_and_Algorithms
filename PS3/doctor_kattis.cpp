#include <bits/stdc++.h>
using namespace std;


class Max_Heap{
private:
  vector<pair<string, pair<int ,int>>> A;
  int heap_size;
public:
  Max_Heap(){
    A.push_back({"DUMMY", {101, 0}}); // 0 index not used in a heap
    heap_size = 0;
  }
  int left(int index){
    return index*2;
  }
  int right(int index){
    return index*2 + 1;
  }
  int parent(int index){
    return index/2;
  }
  void max_heapify(int index){
    int l = left(index);
    int r = right(index);
    int largest = index;
    if (l <= heap_size && A[l].second.first >= A[index].second.first){
      if (A[l].second.first == A[index].second.first){
        if (A[l].second.second < A[index].second.second){
          largest = l;
        }
      }
      else{
        largest = l;
      }
    }
    if (r <= heap_size && A[r].second.first > A[largest].second.first){
      if (A[r].second.first == A[index].second.first){
        if (A[r].second.second < A[index].second.second){
          largest = r;
        }
      }
      else{
        largest = r;
      }
    }
    if (largest != index){
      swap(A[largest], A[index]);
      max_heapify(largest);
    }
  }
  string max(){
    if (heap_size == 0){
      return "The clinic is empty";
    }
    return A[1].first;
  }
  void extract_max(){
    A[1] = A[heap_size];
    heap_size--;
    A.pop_back();
    max_heapify(1);
    return;
  }
  void insert(pair<string, pair<int, int>> p){
    heap_size++;
    A.push_back(p);
    int index = heap_size;
    int parent = index/2;
    while (index > 1 && A[parent].second.first < A[index].second.first){
      swap(A[parent], A[index]);
      index = parent;
      parent = index/2;
    }
  }

  int search(string name){  //returns index
    for (int i = 1; i <= heap_size; i++){
      if (A[i].first == name){
        return i;
      }
    }
    return -1;
  }
  void delete_key(string name){
    if (heap_size == 0){
      return;
    }
    int index = search(name);
    A[index] = A[heap_size];
    heap_size--;
    A.pop_back();
    max_heapify(index);
    return;
  }
  void increase_key(string name, int newv){
    if (heap_size == 0){
      return;
    }
    int index = search(name);
    A[index].second.first += newv;
    int parent = index/2;
    while (index > 1 && A[parent].second.first <= A[index].second.first){
      if (A[parent].second.first == A[index].second.first){
        if (A[parent].second.second > A[index].second.second){
          swap(A[parent], A[index]);
          index = parent;
          parent = index/2;
        }
      }
      else{
        swap(A[parent], A[index]);
        index = parent;
        parent = index/2;
      }
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  Max_Heap clinic;
  for (int i = 0; i < n; i++){
    int command;
    cin >> command;
    if (command == 0){
      string name;
      int level;
      cin >> name >> level;
      clinic.insert({name, {level, i}});
    }
    else if (command == 1){
      string name;
      int increase;
      cin >> name >> increase;
      clinic.increase_key(name, increase);
    }
    else if (command == 2){
      string name;
      cin >> name;
      clinic.delete_key(name);
    }
    else if (command == 3){
      cout << clinic.max() << endl;
    }
  }
}
