#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int s;
    cin >> s;
    vector<int> red;
    vector<int> blue;
    for (int j = 0; j < s; j++){
      string segment;
      cin >> segment;
      int length = 0;
      for (auto &c : segment){
        if (isalpha(c)){
          if (c == 'R'){
            red.push_back(length/10);
          }
          else{
            blue.push_back(length/10);
          }
        }
        else{
          length += int(c) - int('0');
          length *= 10;
        }
      }
    }
    if (red.empty()){
      cout << "Case #" << i + 1 << ": 0\n";
      continue;
    }
    if (blue.empty()){
      cout << "Case #" << i + 1 << ": 0\n";
      continue;
    }
    sort(red.begin(), red.end(), greater<int>());
    sort(blue.begin(), blue.end(), greater<int>());
    int total = 0;
    if (red.size() >= blue.size()){
      for (int k = 0; k < blue.size(); k++){
        total += red[k];
        total += blue[k];
        total -= 2;
      }
    }
    else{
      for (int k = 0; k < red.size(); k++){
        total += red[k];
        total += blue[k];
        total -= 2;
      }
    }
    cout << "Case #" << i + 1 << ": " << total << endl;
  }
}
