#include <bits/stdc++.h>
using namespace std;

int insertion_sort(int arr[], int len){
  int steps = 0;
  for (int i = 1; i < len; i++){
    int x = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > x){
      arr[j+1] = arr[j];
      j--;
      steps++;
    }
    arr[j + 1] = x;
  }
  return steps;
}

int main(){
  int p;
  cin >> p;
  for (int i = 1; i <= p; i++){
    int k;
    cin >> k;
    int arr[20];
    for (int j = 0; j < 20; j++){
      cin >> arr[j];
    }
    cout << i << " " << insertion_sort(arr, 20) << endl;
  }
}
