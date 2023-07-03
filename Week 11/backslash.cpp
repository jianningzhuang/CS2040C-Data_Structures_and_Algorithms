#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n){
    cin.ignore();
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++){
      string curr = "";
      for (auto &c : line){
        if ((int(c) >= 33 && int(c) <= 42) || (int(c) >= 91 && int(c) <= 93)){
          curr += '\\';
          curr += c;
        }
        else{
          curr += c;
        }
      }
      line = curr;
    }
    cout << line << endl;
  }
}
