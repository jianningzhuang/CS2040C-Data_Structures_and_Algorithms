#include <bits/stdc++.h>
using namespace std;

//10:45 to

int main(){
  int n;
  cin >> n;
  unordered_map<string, set<string>> m;
  for (int i = 0; i < n; i++){
    string category;
    int w;
    cin >> category >> w;
    set<string> s;
    for (int j = 0; j < w; j++){
      string key;
      cin >> key;
      s.insert(key);
    }
    m[category] = s;
  }
  string in;
  map<string, int> freq;
  while (cin >> in){
    for (auto it = m.begin(); it != m.end(); it++){
      if ((it->second).find(in) != (it->second).end()){
        freq[it->first]++;
      }
    }
  }
  int largest = 0;
  for (auto is = freq.begin(); is != freq.end(); is++){
    if (is->second > largest){
      largest = is->second;
    }
  }
  for (auto is = freq.begin(); is != freq.end(); is++){
    if (is->second == largest){
      cout << is->first << endl;
    }
  }
}
