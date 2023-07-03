#include <bits/stdc++.h>
using namespace std;


void counting_sort(vector<int> arr, int n){
    map<int, int> freqMap;
    for (auto i = arr.begin(); i != arr.end(); i++) {
        freqMap[*i]++;
    }
    int i = 0;
    for (auto it : freqMap) {
        int val = it.first;
        int freq = it.second;
        for (int j = 0; j < freq; j++)
            arr[i++] = val;
    }
}


int main(){
  int N;
  cin >> N;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < N; i++){
    int A, B;
    cin >> A >> B;
    a.push_back(A);
    b.push_back(B);
    counting_sort(a, a.size());
    counting_sort(b, b.size());
    if (a[0] + b[i] < a[i] + b[0]){
      cout << a[i] + b[0] << endl;
    }
    else{
      cout << a[0] + b[i] << endl;
    }
  }
}
