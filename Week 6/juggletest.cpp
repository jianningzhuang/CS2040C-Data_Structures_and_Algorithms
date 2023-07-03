#include <bits/stdc++.h>
using namespace std;

int main(){
  string pattern;
  while (cin >> pattern){
    int sum = 0;
    int count = 0;
    for (auto &d : pattern){
      sum += int(d) - int('0');
      count++;
    }
    if (sum%count != 0){
      cout << pattern << ": invalid # of balls\n";
    }
    else{
      vector<int> left;
      vector<int> right;
      int timer = 0;
      bool flag = true;
      for (auto &c : pattern){
        timer++;
        for (auto i = left.begin(); i != left.end(); i++){
          if (*i == 1){
            left.erase(i);
          }
          else{
            int temp = *i;
            temp -= 1;
            left.erase(i);
            left.insert(temp);
          }
        }
        for (auto i = right.begin(); i != right.end(); i++){
          if (*i == 1){
            right.erase(i);
          }
          else{
            int temp = *i;
            temp -= 1;
            right.erase(i);
            right.insert(temp);
          }
        }
        int ball = int(c) - int('0');
        if (ball == 0){
          continue;
        }
        if (timer%2 == 1){
          if (left.find(ball) != left.end()){
            flag = false;
            cout << pattern << ": invalid pattern\n";
            break;
          }
          else{
            left.insert(ball);
          }
        }
        else{
          if (right.find(ball) != right.end()){
            flag = false;
            cout << pattern << ": invalid pattern\n";
            break;
          }
          else{
            right.insert(ball);
          }
        }
      }
      if (flag == true){
        cout << pattern << ": valid with " << sum/count << " balls\n";
      }
    }
  }
}
