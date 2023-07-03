#include <bits/stdc++.h>
using namespace std;

// #Student Num: A0214561M
// #NUSNET ID: E0527277
// #Q0: A0214561M

//1.O(1)
//2.O(n)
//3.O(n)
//4.O(n^2)
//5.O(nlogn)
//6.O(n)
//7.O(1)
//8.O(n)
//9.O(n)
//10.O(1)


//1.If no user-declared constructors of any kind are provided for a class type (struct, class, or union),
//the compiler will always declare a default constructor as an inline public member of its class.

//2.bubble sort is both in place and stable

//3.no, in that one level, we have to compare all the elements to merge them back into the sorted array
//this process is similar to finding min in selection sort O(n^2)

//4.if the array is already sorted, insertion sort runs in O(n) while mergesort still runs in O(nlogn)

//5.yes, traverse the SLL and push into a stack O(n)
//then pop each element O(n)  => O(n) + O(n) = O(n)

//1.4132657

//2.

//3.543212345


//Special case 1: traverse the list once to find max and min of whole class O(n)

//Special case 2: just take their difference and absolute value O(1)

//General case: O(nlogn) with std::sort but O(n) with radix?

// int main(){
//   int n,k;
//   cin >> n >> k;
//   int scores[n];
//   for (int i = 0; i < n; i++){
//     cin >> scores[i];
//   }
//   sort(scores, scores + n);
//   int min = -1;
//   for (int i = 0; i < n - k + 1; i++){
//     if (min == -1 || (scores[i+k-1] - scores[i]) < min){
//       min = (scores[i+k-1] - scores[i]);
//     }
//   }
//   cout << min << endl;
// }


//Stack

int main(){
  int n, p;
  cin >> n >> p;
  unordered_map<int, int> route;
  for (int i = 0; i < p; i++){
    int start, end;
    cin >> start >> end;
    if (start < end){
      route[start] = end;
    }
    else{
      cout << "Bus cannot go backwards!\n";
      return 0;
    }
  }
  stack<int> s;
  for (int i = 1; i <= n; i++){
    if (!s.empty()){
      if (s.top() == i){
        s.pop();
      }
      else if (s.top() < i){
        cout << "Missed stop!\n";
        return 0;
      }
    }
    if (route.find(i) != route.end()){
      s.push(route[i]);
    }
  }
  cout << "yes\n";
}
