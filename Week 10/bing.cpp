#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_map<string, int> m;
  for (int i = 0; i < n; i++){
    string word;
    cin >> word;
    cout << m[word] << endl;
    string temp = "";
    for (auto &c : word){
      temp += c;
      m[temp]++;
    }
  }
}
