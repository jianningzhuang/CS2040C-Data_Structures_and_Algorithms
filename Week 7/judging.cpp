#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_map<string, int> dom;
  unordered_map<string, int> kattis;
  for (int i = 0; i < n; i++){
    string output;
    cin >> output;
    dom[output]++;
  }
  for (int i = 0; i < n; i++){
    string output;
    cin >> output;
    kattis[output]++;
  }
  int total = 0;
  for (auto i = dom.begin(); i != dom.end(); i++){
    string output = i->first;
    int freq1 = i->second;
    if (kattis.find(output) != kattis.end()){
      int freq2 = kattis[output];
      if (freq1 >= freq2){
        total += freq2;
      }
      else{
        total += freq1;
      }
    }
  }
  cout << total << endl;
}
