#include <bits/stdc++.h>
using namespace std;

vector<int> merge_lists(vector<vector<int>> v, int k, int n){
  vector<int> result;
  while (result.size() != n){
    int min_value = -1;
    int min_list = -1;
    for (int i = 0; i < k; i++){
      if (v[i].empty()){
        continue;
      }
      else{
        if (min_value == -1 || v[i][0] < min_value){
          min_value = v[i][0];
          min_list = i;
        }
      }
    }
    result.push_back(min_value);
    cout << min_value << endl;
    v[min_list].erase(v[min_list].begin());
  }
  return result;
}

// void merge_sort(vector<int> &v, int k){
//   if (v.size() < 2){
//     return;
//   }
//   vector<vector<int>> split;
//   int increment;
//   if (v.size()%k == 0){
//     increment = v.size()/k;
//   }
//   else{
//     increment = v.size()/k + 1;
//   }
//   for (int i = 0; i < v.size(); i += increment){
//     split.push_back();
//   }
// }

int main(){
  vector<vector<int>> v = {{1,3,5}, {2,4,7}, {6,8,9}};
  vector<int> result = merge_lists(v, 3, 9);
}
