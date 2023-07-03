#include <bits/stdc++.h>
using namespace std;

//8:22 to

int main(){
  int n;
  cin >> n;
  unordered_map<string, int> freq;
  for (int i = 0; i < n; i++){
    string word;
    cin >> word;
    string keys = "";
    for (auto &c : word){
      if (c == 'a' || c == 'b' || c == 'c'){
        keys += '2';
      }
      else if (c == 'd' || c == 'e' || c == 'f'){
        keys += '3';
      }
      else if (c == 'g' || c == 'h' || c == 'i'){
        keys += '4';
      }
      else if (c == 'j' || c == 'k' || c == 'l'){
        keys += '5';
      }
      else if (c == 'm' || c == 'n' || c == 'o'){
        keys += '6';
      }
      else if (c == 'p' || c == 'q' || c == 'r' || c == 's'){
        keys += '7';
      }
      else if (c == 't' || c == 'u' || c == 'v'){
        keys += '8';
      }
      else if (c == 'w' || c == 'x' || c == 'y' || c == 'z'){
        keys += '9';
      }
    }
    freq[keys]++;
  }
  string presses;
  cin >> presses;
  cout << freq[presses] << endl;
}
