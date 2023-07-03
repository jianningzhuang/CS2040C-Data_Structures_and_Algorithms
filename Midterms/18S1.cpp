#include <bits/stdc++.h>
using namespace std;

// int main(){
//   string a, b;
//   cin >> a >> b;
//   sort(a.begin(), a.end());
//   sort(b.begin(), b.end());
//   for (int i = 0; i < a.size(); i++){
//     if (a[i] != b[i]){
//       cout << "No\n";
//       return 0;
//     }
//   }
//   cout << "Yes\n";
// }

// int main(){
//   string a, b;
//   cin >> a >> b;
//   unordered_map<char, int> freqa;
//   unordered_map<char, int> freqb;
//   for (auto &c : a){
//     freqa[c] += 1;
//   }
//   for (auto &c : b){
//     freqb[c] += 1;
//   }
//   for (auto &c : a){
//     if (freqa[c] != freqb[c]){
//       cout << "No\n";
//       return 0;
//     }
//   }
//   cout << "Yes\n";
// }

// class SLL {
// struct Vertex {
// int item;
// Vertex *next;
// };
// private:
// Vertex *head, *tail;
// public:
// SLL() {
// head = tail = NULL;
// }
// void InsertAtHead(int value) {
// Vertex *vtx = new Vertex();
// vtx->item = value;
// vtx->next = head;
// if (head == NULL) tail = vtx; // first insertion
// head = vtx;
// }
// void InsertAfterTail(int value) {
// if (head == NULL)
// InsertAtHead(value); // special case
// else {
// Vertex *vtx = new Vertex();
// vtx->item = value;
// tail->next = vtx;
// tail = vtx;
// }
// }
// void PrintList() {
// for (Vertex *vtx = head; vtx != NULL; vtx = vtx->next)
// cout << vtx->item << " ";
// cout << endl;
// }
// SLL Partition() {
//   SLL result;
//   int pivot = head->item;
//   result.InsertAtHead(pivot);
//   Vertex* curr = head->next;
//   while (curr != NULL){
//     if (curr->item < pivot){
//       result.InsertAtHead(curr->item);
//     }
//     else{
//       result.InsertAfterTail(curr->item);
//     }
//     curr = curr->next;
//   }
//   return result;
// }
// };
// int main() {
// SLL L, Lmod;
// L.InsertAfterTail(5); L.InsertAfterTail(8); L.InsertAfterTail(6);
// L.InsertAfterTail(1); L.InsertAfterTail(7); L.InsertAfterTail(2);
// Lmod = L.Partition();
// L.PrintList(); // should remain 5->8->6->1->7->2
// Lmod.PrintList(); // [smaller than 5] -> 5 -> [bigger than 5]
// return 0;
// }

class StackRememberMax{
private:
  int max;
  stack<pair<int, int>> s;
public:
  void push(int value){
    if (s.empty()){
      max = value;
      s.push({value, -1});
    }
    else{
      if (value > max){
        s.push({value, max});
        max = value;
      }
      else{
        s.push({value, -1});
      }
    }
  }
  int top(){
    return s.top().first;
  }
  int pop(){
    int t = s.top().first;
    if (t == max){
      max = s.top().second;
      s.pop();
      return t;
    }
    else{
      s.pop();
      return t;
    }
  }
  int findMax(){
    if (s.empty()){
      return -1;
    }
    return max;
  }
};

int main() {
StackRememberMax S;
cout << S.findMax() << endl; // should be -1
S.push(2); S.push(7); S.push(1);
S.push(6); S.push(8); S.push(5);
cout << S.top() << endl; // should be 5
cout << S.findMax() << endl; // should be 8
S.pop(); // pop 5 out
cout << S.top() << endl; // should be 8 now
cout << S.findMax() << endl; // should still be 8
S.pop(); // pop 8 out
cout << S.top() << endl; // should be 6 now
cout << S.findMax() << endl; // should now be 7
}

// int main(){
//   int n;
//   cin >> n;
//   deque<int> dq;
//   for (int i = 0; i < n; i++){
//     int val;
//     cin >> val;
//     dq.push_back(val);
//   }
//   string command;
//   cin >> command;
//   bool reverse = false;
//   for (auto &c : command){
//     if (c == 'R'){
//       if (reverse == false){
//         reverse = true;
//       }
//       else{
//         reverse = false;
//       }
//     }
//     else if (c == 'D'){
//       if (dq.empty()){
//         cout << "Error\n";
//         return 0;
//       }
//       else{
//         if (reverse){
//           dq.pop_back();
//         }
//         else{
//           dq.pop_front();
//         }
//       }
//     }
//   }
//   if (reverse){
//     for (auto i = dq.rbegin(); i != dq.rend(); i--){
//       cout << *i;
//     }
//   }
//   else{
//     for (auto i = dq.begin(); i != dq.end(); i++){
//       cout << *i;
//     }
//   }
// }
