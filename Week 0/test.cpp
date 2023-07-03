#include <iostream>
#include <algorithm>
using namespace std;

long long test_1(long long arr[], long long size){
  for (long long a = 0; a < size - 1; a++){
    for (long long b = a + 1; b < size; b++){
      if (arr[a] + arr[b] == 7777){
        return 1;
      }
    }
  }
  return 0;
}

long long test_2(long long arr[], long long size){
  for (long long a = 0; a < size - 1; a++){
    for (long long b = a + 1; b < size; b++){
      if (arr[a] == arr[b]){
        return 1;
      }
    }
  }
  return 0;
}

long long frequency(long long arr[], long long size, long long target){
  long long result = 0;
  for (long long i = 0; i < size; i++){
    if (arr[i] == target){
      result += 1;
    }
  }
  return result;
}

long long search(long long arr[], long long size, long long target){
  for (long long x = 0; x < size; x++){
    if (arr[x] == target){
      return 1;
    }
  }
  return 0;
}

long long test_3(long long arr[], long long size){
  long long seen[size];
  fill_n(seen, size, -1);
  for (long long i = 0; i < size; i++){
    if (search(seen, i, arr[i])){
      continue;
    }
    else{
      seen[i] == arr[i];
      if (frequency(arr, size, arr[i]) > size/2){
        return arr[i];
      }
    }
  }
  return -1;

}

int main(){
  long long N, t;
  cin >> N >> t;
  long long arr[N];
  for (long long i = 0; i < N; i++){
    cin >> arr[i];
  }
  if (t == 1){
    long long found = test_1(arr, N);
    if (found == 1){
      cout << "Yes\n";
    }
    else{
      cout << "No\n";
    }
  }
  else if (t == 2){
    long long duplicate = test_2(arr, N);
    if (duplicate == 1){
      cout << "Contains duplicate\n";
    }
    else{
      cout << "Unique\n";
    }
  }
  else if (t == 3){
    long long ans = test_3(arr, N);
    cout << ans << "\n";
  }
  else if (t == 4){
    sort(arr, arr + N);
    if (N%2 == 1){
      cout << arr[N/2 + 1];
    }
    else{
      cout << arr[N/2 - 1] << " " << arr[N/2];
    }
  }
  else if (t == 5){
    sort(arr, arr + N);
    for (int i = 0; i < N; i++){
      if (arr[i] >= 100 && arr[i] <= 999){
        cout << arr[i] << " ";
      }
    }
  }
}
