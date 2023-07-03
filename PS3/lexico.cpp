#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld numberfy(string name){
  ld result = 0;
  int count = 0;
  for (auto &c : name){
    result += double(int(tolower(c)) - int('a'))/double(10);
    result *= double(26)/double(10);
    count++;
  }
  for (int i = 0; i < 10-count; i++){
    result *= double(26)/double(10);
  }
  ld max = 1;
  for (int i = 0; i < 11; i++){
    max *= double(26)/double(10);
  }
  result = max - result;
  for (int i = 0; i < 5; i++){
    result /= double(10);
  }
  return result;
}

int main(){
  string n1 = "abcd";
  string n2 = "abcde";
  cout << numberfy(n1) << endl;
  cout << numberfy(n2) << endl;
  cout << int(numberfy(n1) > numberfy(n2));
}
