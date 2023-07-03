#include <bits/stdc++.h>
using namespace std;

void print_map(map<int,int> &m){
  for (auto i = m.begin(); i != m.end(); i++){
    cout << i->first << ": " << i->second << "\n";
  }
  cout << endl;
}

void test_1(vector<int> &v, int target){
  int l = 0;
  int r = v.size() - 1;
  while (l < r){
    if (v[l] + v[r] == target){
      cout << "Yes\n";
      return;
    }
    else if (v[l] + v[r] < target){
      l++;
    }
    else{
      r--;
    }
  }
  cout << "No\n";
  return;
}

void test_2(map<int, int> &m){
  for (auto i = m.begin(); i != m.end(); i++){
    if (i->second > 1){
      cout << "Contains duplicate\n";
      return;
    }
  }
  cout << "Unique\n";
  return;
}

void test_3(map<int, int> &m, int n){
  for (auto i = m.begin(); i != m.end(); i++){
    if (i->second > n/2){
      cout << i->first << endl;
      return;
    }
  }
  cout << -1 << endl;
  return;
}

void test_4(vector<int> &v, int n){
  if (n%2 == 1){
    cout << v[n/2] << endl;
  }
  else{
    cout << v[n/2 - 1] << " " << v[n/2] << endl;
  }
}

void test_5(vector<int> &v){
  for (auto i = v.begin(); i != v.end(); i++){
    if (*i >= 100 && *i <= 999){
      cout << *i << " ";
    }
  }
  cout << endl;
}

int main(){
  int n, t;
  cin >> n >> t;
  vector<int> v;
  for (int i = 0; i < n; i++){
    int num;
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end()); // sort outside
  map<int, int> frequency;
  for (int i = 0; i < n; i++){
    if (frequency.find(v[i]) == frequency.end()){
      frequency[v[i]] = 1;
    }
    else{
      frequency[v[i]]++;
    }
  }
  switch (t){
    case 1:
      test_1(v, 7777);
      break;
    case 2:
      test_2(frequency);
      break;
    case 3:
      test_3(frequency, n);
      break;
    case 4:
      test_4(v, n);
      break;
    case 5:
      test_5(v);
      break;
  }
}
