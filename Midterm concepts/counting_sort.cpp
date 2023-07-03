#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &v){
  for (auto i = v.begin(); i != v.end(); i++){
    cout << *i << " ";
  }
  cout << endl;
}

void counting_sort(vector<int> &v){
  vector<int> freq(10);
  for (int i = 0; i < v.size(); i++){
    freq[v[i]]++;
  }
  v.clear();
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < freq[i]; j++){
      v.push_back(i);
    }
  }
}

int main(){
  vector<int> v = {4,3,5,6,4,3,2,1,3,5};
  print_vector(v);
  counting_sort(v);
  print_vector(v);
}
