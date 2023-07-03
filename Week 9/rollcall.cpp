#include <bits/stdc++.h>
using namespace std;

//1017 to

int main(){
  map<string, set<string>> names;
  unordered_map<string, int> freq;
  string first, last;
  while (cin >> first && cin >> last && first != "Jianning"){
    names[last].insert(first);
    freq[first]++;
  }
  for (auto it = names.begin(); it != names.end(); it++){
    for (auto is = (it->second).begin(); is != (it->second).end(); is++){
      if (freq[*is] > 1){
        cout << *is << " " << it->first << endl;
      }
      else {
        cout << *is << endl;
      }
    }
  }

}
