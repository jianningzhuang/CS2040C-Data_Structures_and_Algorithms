#include <bits/stdc++.h>
using namespace std;

int main(){
  string data;
  while (getline(cin, data)){
    double total = 0;
    int count = 0;
    string name = "";
    string info = "";
    for (auto &c: data){
      if (c == ' '){
        if (isalpha(info[0])){
          name += info;
          name += ' ';
          info = "";
        }
        else{
          total += stod(info);
          count += 1;
          info = "";
        }
      }
      else{
        info += c;
      }
    }
    if (isalpha(info[0])){
      name += info;
    }
    else{
      total += stod(info);
      count += 1;
    }
    cout << fixed << setprecision(12) << total/count << " " << name << endl;
  }
}
