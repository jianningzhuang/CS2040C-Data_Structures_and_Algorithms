#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int len){
  for (int i = 0; i < len; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

// void bubble_sort(int arr[], int len){
//   for (int i = 0; i < len - 1; i++){
//     for (int j = 0; j < len - 1 - i; j++){
//       if (arr[j] > arr[j+1]){
//         int temp;
//         temp = arr[j];
//         arr[j] = arr[j+1];
//         arr[j+1] = temp;
//       }
//     }
//   }
// }

void early_bubble(int arr[], int len){
  bool swapped;
  do{
    swapped = false;
    for (int i = 0; i < len - 1; i++){
      if (arr[i] < arr[i+1]){
        swap(arr[i], arr[i+1]);
        swapped = true;
      }
    }
  }
  while (swapped);
}

// void early_terminate(int arr[], int len){
//   int counter = 0;
//   bool swapped;
//   for (int i = 0; i < len - 1; i++){
//     swapped = false;
//     for (int j = 0; j < len - 1 - i; j++){
//       counter++;
//       if (arr[j] > arr[j+1]){
//         int temp;
//         temp = arr[j];
//         arr[j] = arr[j+1];
//         arr[j+1] = temp;
//         swapped = true;
//       }
//     }
//     if (swapped == false){
//       break;
//     }
//   }
//   cout << counter << endl;
// }




int main(){
  int arr[] = {6,1,2,3,4,5};
  print_array(arr, 6);
  early_bubble(arr, 6);
  print_array(arr, 6);
}
