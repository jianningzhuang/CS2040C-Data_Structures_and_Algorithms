#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<string> &v){
  for (vector<string>::iterator i = v.begin(); i != v.end(); i++){
    cout << *i << endl;
  }
  cout << endl;
}


bool second_digit(string a, string b){
  return a[1] < b[1];
}
bool first_digit(string a, string b){
  return a[0] < b[0];
}

int main(){
  int n;
  while (cin >> n && n != 0){
    vector<string> v;
    for (int i = 0; i < n; i++){
      string name;
      cin >> name;
      v.push_back(name);
    }
    stable_sort(v.begin(), v.end(), second_digit);
    stable_sort(v.begin(), v.end(), first_digit);
    print_vector(v);
  }

}
