#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  int P;
  cin >> P;
  for (int i = 0; i < P; i++){
    int k;
    string fraction;
    cin >> k >> fraction;
    stringstream ss(fraction);
    string token;
    getline(ss, token, '/');
    ll p = stoi(token);
    getline(ss, token, '/');
    ll q = stoi(token);
    string sequence = "";
    while (p != 1 || q != 1){
      if (p > q){
        p = p - q;
        sequence += "R";
      }
      else{
        q = q - p;
        sequence += "L";
      }
    }
    reverse(sequence.begin(), sequence.end());
    ll index = 1;
    for (auto &c : sequence){
      if (c == 'R'){
        index = index*2 + 1;
      }
      else{
        index = index*2;
      }
    }
    cout << k << " " << index << endl;
  }
}
