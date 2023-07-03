#include <bits/stdc++.h>
using namespace std;

int string_recur(vector<string> v, string target, int low, int high){
  if (low > high){
    return -1;
  }
  int mid = (low + high)/2;
  if (v[mid] == target){
    return mid;
  }
  else if (v[mid] < target){
    return string_recur(v, target, mid + 1, high);
  }
  else{
    return string_recur(v, target, low, mid - 1);
  }
}

int binary_string(vector<string> v, string target){
  return string_recur(v, target, 0, v.size() - 1);
}

int main(){
  vector<string> v = {"alan", "bobby", "carl", "tommy", "zhuang"};
  cout << binary_string(v, "sir");
}
