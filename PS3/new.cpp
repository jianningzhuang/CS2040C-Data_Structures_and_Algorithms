#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld numberfy(string name){
  ld result = 0;
  int count = 0;
  for (auto &c : name){
    result += double(int(c))/8;
    result *= 32;
    count++;
  }
  for (int i = 0; i < 10-count; i++){
    result *= 32;
  }
  ld max = 1;
  for (int i = 0; i < 11; i++){
    max *= 32;
  }
  result = max - result;
  for (int i = 0; i < 17; i++){
    result /= 10;
  }
  return result;
}

class binary_heap {
private:
  vector<pair<ld, string>> compact_vector; // the underlying data structure, we will ignore index 0
  int heap_size;

  // three helper navigation function, written in bit manipulation format to improve runtime speed, all three are fast O(1) functions
  int parent(int i) { return i>>1; } // i>>1 is the same as i/2
  int left(int i) { return i<<1; } // i<<1 is the same as i*2
  int right(int i) { return (i<<1)+1; } // (i<<1)+1 is the same as i*2+1

  void shift_up(int i) { // O(log n)
    if (i == 1) return; // at root, do nothing
    if (compact_vector[i].first > compact_vector[parent(i)].first) { // violate property with parent
      swap(compact_vector[i], compact_vector[parent(i)]); // swap upwards
      shift_up(parent(i)); // recurse, at most O(log n) steps back to the root
    }
  }

  void shift_down(int i) { // O(log n)
    if (i > heap_size) return; // beyond last element, do nothing
    int swap_id = i;
    if ((left(i) <= heap_size) && (compact_vector[i].first < compact_vector[left(i)].first)) { // compare with left child, if exists
      swap_id = left(i);
    }
    if ((right(i) <= heap_size) && (compact_vector[swap_id].first < compact_vector[right(i)].first)) { // compare with right child, if exists
      swap_id = right(i);
    }
    if (swap_id != i) { // need to swap with the larger of the two children
      swap(compact_vector[i], compact_vector[swap_id]); // swap downwards with the larger of the two children
      shift_down(swap_id); // recurse, at most O(log n) steps to one of the bottom-most leaf
    }
  }

public:
  binary_heap() { // O(1)
    compact_vector.clear(); // clear the vector
    compact_vector.push_back({-1, "DUMMY"}); // remember to set index 0 to be 'dummy'
    heap_size = 0; // an empty Binary Heap
  }

  void insert(pair<ld, string> p) { // O(log n)
    if (heap_size+1 >= (int)compact_vector.size()) { // O(1)
      compact_vector.push_back({0, "EXTRA"}); // enlarge the vector by one if needed, to avoid potential RTE below, O(1)
    }
    compact_vector[++heap_size] = p; // the only possible insertion point, O(1)
    shift_up(heap_size); // shift upwards, O(log n) at worst
  }
  void pop() { // O(log n)
    swap(compact_vector[1], compact_vector[heap_size--]); // swap with the last existing leaf, O(1)
    shift_down(1); // fix heap property downwards, O(log n) at worst
    return; // return the maximum value, O(1)
  }

  void delete_key(string name){
    int index = 0;
    for (int i = 1; i < compact_vector.size(); i++){
      if (compact_vector[i].second == name){
        index = i;
        break;
      }
    }
    swap(compact_vector[index], compact_vector[heap_size--]); // swap with the last existing leaf, O(1)
    shift_down(index); // fix heap property downwards, O(log n) at worst
    return;
  }

  string top() { // O(1)
    return compact_vector[1].second; // this is the root
  }

  bool empty() { // O(1)
    return heap_size == 0; // the only condition for an empty compact_vector
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  binary_heap pq;
  for (int i = 0; i < n; i++){
    int q;
    cin >> q;
    if (q == 1){
      ll time, severity;
      string name;
      cin >> time >> name >> severity;
      ld priority = severity - k*time;
      priority /= 1000;
      priority += numberfy(name);
      pq.insert({priority, name});
    }
    else if (q == 2){
      ll time;
      cin >> time;
      if (pq.empty()){
        cout << "doctor takes a break\n";
      }
      else{
        string name = pq.top();
        cout << name << endl;
        pq.pop();
        bool found = false;
      }
    }
    else if (q == 3){
      ll time;
      string name;
      cin >> time >> name;
      pq.delete_key(name);
    }
  }
}
