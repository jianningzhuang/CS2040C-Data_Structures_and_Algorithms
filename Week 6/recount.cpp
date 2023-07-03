#include <bits/stdc++.h>
using namespace std;

int main(){
  string line;
  getline(cin, line);
  unordered_map<string, int> freq;
  while (line != "***"){
    if (freq.find(line) == freq.end()){
      freq[line] = 0;
    }
    freq[line] += 1;
    getline(cin, line);
  }
  int runoff = 0;
  int max = 0;
  string winner = "";
  for (auto i = freq.begin(); i != freq.end(); i++){
    if (i->second > max){
      max = i-> second;
      winner = i->first;
      runoff = 0;
    }
    else if (i->second == max){
      runoff = 1;
    }
  }
  if (runoff == 0){
    cout << winner << endl;
  }
  else{
    cout << "Runoff!\n";
  }
}
