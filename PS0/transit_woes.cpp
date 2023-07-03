#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &v){
  for (auto i = v.begin(); i != v.end(); i++){
    cout << *i << " ";
  }
  cout << endl;
}

int main(){
  int s, t, n;
  cin >> s >> t >> n;
  vector<int> walking;
  vector<int> bus;
  vector<int> interval;
  for (int i = 0; i <= n; i++){
    int time;
    cin >> time;
    walking.push_back(time);
  }
  for (int i = 0; i < n; i++){
    int time;
    cin >> time;
    bus.push_back(time);
  }
  for (int i = 0; i < n; i++){
    int time;
    cin >> time;
    interval.push_back(time);
  }
  int current = s + walking[0];
  for (int i = 0; i < n; i++){
    while (current%interval[i] != 0){
      current++;
    }
    current += bus[i];
    current += walking[i+1];
  }
  if (current <= t){
    cout << "yes\n";
  }
  else{
    cout << "no\n";
  }
}
