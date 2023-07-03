#include <bits/stdc++.h>
using namespace std;

int main(){
  string line;
  cin >> line;
  vector<int> table(4);
  int total = 0;
  for (auto &c : line){
    total++;
    if (isalpha(c) && islower(c)){
      table[0] += 1;
    }
    else if (isalpha(c) && isupper(c)){
      table[1] += 1;
    }
    else if (c == '_'){
      table[2] += 1;
    }
    else{
      table[3] += 1;
    }
  }
  double ratio;
  ratio = double(table[2])/double(total);
  cout << fixed << setprecision(12) << ratio << endl;
  ratio = double(table[0])/double(total);
  cout << fixed << setprecision(12) << ratio << endl;;
  ratio = double(table[1])/double(total);
  cout << fixed << setprecision(12) << ratio << endl;;
  ratio = double(table[3])/double(total);
  cout << fixed << setprecision(12) << ratio << endl;;
}
