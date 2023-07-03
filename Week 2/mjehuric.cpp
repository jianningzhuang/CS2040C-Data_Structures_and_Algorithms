#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int len){
  for (int i = 0; i < len; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void bubble_sort(int arr[], int len){
  for (int i = 0; i < len - 1; i++){
    for (int j = 0; j < len - 1 - i; j++){
      if (arr[j] > arr[j+1]){
        int temp;
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        print_array(arr, len);
      }
    }
  }
}

int main(){
  int arr[5];
  for (int i = 0; i < 5; i++){
    int x;
    cin >> x;
    arr[i] = x;
  }
  bubble_sort(arr, 5);

}
