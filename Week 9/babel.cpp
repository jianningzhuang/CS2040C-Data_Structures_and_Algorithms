#include <bits/stdc++.h>
using namespace std;

int main(){
  string eng;
  unordered_map<string, string> m;
  while (getline(cin, eng) && eng != ""){
    stringstream check1(eng);
    string temp;
    vector<string> v;
    while (getline(check1, temp, ' ')){
      v.push_back(temp);
    }
    m[v[1]] = v[0];
  }
  string outp;
  while (cin >> outp){
    if (m.find(outp) != m.end()){
      cout << m[outp] << endl;
    }
    else{
      cout << "eh\n";
    }
  }

}
