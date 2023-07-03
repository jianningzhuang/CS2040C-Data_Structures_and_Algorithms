#include <bits/stdc++.h>
using namespace std;

int main(){
  string line;
  unordered_map<string, int> sti;
  unordered_map<int, string> its;
  while (getline(cin, line)){
    stringstream check1(line);
    string temp;
    vector<string> v;
    while (getline(check1, temp, ' ')){
      v.push_back(temp);
    }
    if (v[0] == "clear"){
      sti.clear();
      its.clear();
    }
    else if (v[0] == "def"){
      if (sti.find(v[1]) != sti.end()){
        its.erase(sti[v[1]]);
        sti.erase(v[1]);
      }
      sti[v[1]] = stoi(v[2]);
      its[stoi(v[2])] = v[1];
    }
    else if (v[0] == "calc"){
      int sum = 0;
      bool positive = true;
      bool unknown = false;
      for (int i = 1; i < v.size(); i++){
        cout << v[i] << " ";
        if (v[i] == "-"){
          positive = false;
        }
        else if (v[i] == "+"){
          positive = true;
        }
        else if (v[i] == "="){
          continue;
        }
        else if (sti.find(v[i]) != sti.end()){
          if (positive){
            sum += sti[v[i]];
          }
          else{
            sum -= sti[v[i]];
          }
        }
        else if (sti.find(v[i]) == sti.end()){
          unknown = true;
        }
      }
      if (unknown){
        cout << "unknown";
      }
      else{
        if (its.find(sum) != its.end()){
          cout << its[sum];
        }
        else{
          cout << "unknown";
        }
      }
      cout << endl;
    }
  }
}
