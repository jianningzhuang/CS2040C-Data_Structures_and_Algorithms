#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int len){
  for (int i = 0; i < len; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void quicksort(int arr[], int l, int r){
  if (l < r){
    int mid = (l + r)/2;
    int pivot = arr[mid];
    vector<int> smaller;
    vector<int> larger;
    for (int i = l; i <= r; i++){
      if (i != mid){
        if (arr[i] < pivot){
          smaller.push_back(arr[i]);
        }
        else if (arr[i] > pivot){
          larger.push_back(arr[i]);
        }
        else{
          if (i < mid){
            smaller.push_back(arr[i]);
          }
          else{
            larger.push_back(arr[i]);
          }
        }
      }
    }
    int k = l;
    for (auto i = smaller.begin(); i != smaller.end(); i++){
      arr[k] = *i;
      k++;
    }
    int m = k;
    quicksort(arr, l, m - 1);
    arr[k] = pivot;
    k++;
    for (auto i = larger.begin(); i != larger.end(); i++){
      arr[k] = *i;
      k++;
    }
    quicksort(arr, m + 1, k - 1);
  }
}

int main(){
  int arr[] = {61,52,43,54,25,16};
  print_array(arr, 6);
  quicksort(arr, 0, 5);
  print_array(arr, 6);
}
