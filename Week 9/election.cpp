#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  unordered_map<string, string> aff;
  unordered_map<string, int> freq;
  for (int i = 0; i < n; i++){
    string name;
    getline(cin, name);
    string party;
    getline(cin, party);
    aff[name] = party;
    freq[name] = 0;
  }
  int m;
  cin >> m;
  cin.ignore();
  for (int i = 0; i < m; i++){
    string name;
    getline(cin, name);
    if (aff.find(name) != aff.end()){
      freq[name]++;
    }
  }
  int largest = 0;
  for (auto it = freq.begin(); it != freq.end(); it++){
    if ((it->second) > largest){
      largest = it->second;
    }
  }
  bool dup = false;
  string winner = "";
  for (auto it = freq.begin(); it != freq.end(); it++){
    if ((it->second) == largest){
      if (winner != ""){
        dup = true;
      }
      else{
        winner = aff[it->first];
      }
    }
  }
  if (dup){
    cout << "tie\n";
  }
  else{
    cout << winner << endl;
  }
}
