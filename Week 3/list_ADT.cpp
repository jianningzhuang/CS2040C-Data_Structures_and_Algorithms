#include <bits/stdc++.h>
using namespace std;

class List{
private:
  int N; //current number of elements
  int A[10]; //compact ListArray
public:
  List(){
    N = 0;
  }
  int get(int i){
    return A[i]; //question 1c
  }
  int search(int v){
    for (int i = 0; i < N; i++){
      if (A[i] == v){
        return i;
      }
    }
    return -1;
  }
  void insert(int i, int v){
    if ((N == 10) || (i < 0) || (i > N)){ //question 1d
      return;
    }
    for (int j = N; j >= i; j--){ //question 1e
      A[j+1] = A[j];
    }
    A[i] = v;
    ++N;
  }
  void remove(int i){
    for (int j = i; j < N - 1; ++j){ //question 1f
      A[j] = A[j+1];
    }
    --N;
  }
  void printList(){
    for (int i = 0; i < N; ++i){
      if (i) cout << " ";
      cout << A[i];
    }
    cout << endl;
  }
  void sortList(){ //question 1g
    for (int i = 1; i < N; i++){
      int x = A[i];
      int j = i - 1;
      for (j; j >= 0 && A[j] > x; j--){
        A[j+1] = A[j];
      }
      A[j+1] = x;
    }
  }
};

int main() {
  List LA; // question 1h
  LA.insert(0, 5);
  LA.insert(0, 1);
  LA.insert(0, 4);
  LA.insert(0, 7);
  LA.insert(0, 2); // we should have A = {2, 7, 4, 1, 5} by now
  LA.printList();
  cout << LA.get(1) << endl;
  cout << LA.search(4) << endl; // 2, A[2] = 4
  cout << LA.search(6) << endl; // not found, -1
  LA.remove(1); // we should have A = {2, 4, 1, 5} by now
  cout << LA.search(4) << endl; // 1, A[1] = 4 now
  cout << LA.search(7) << endl; // not found, -1
  LA.printList(); // unsorted
  LA.sortList(); // we should have A = {1, 2, 4, 5} by now
  LA.printList(); // sorted
  return 0;
}
