#include <iostream>
using namespace std;

void print_array(int arr[], int len){
  for (int i = 0; i < len; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void merge(int arr[], int l, int m, int r){
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++){
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++){
    R[j] = arr[m + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int l, int r){
  if (l < r){
    int m = l + (r-l)/2;
    merge_sort(arr, l, m);  //mergesort will recursively sort left subarray before right
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}

// pros and cons of mergesort


int main(){
  int arr[] = {3,7,1,6,9,10,11,1};
  int len = sizeof(arr)/sizeof(arr[0]);
  print_array(arr, len);
  merge_sort(arr, 0, len - 1);
  print_array(arr, len);
}
