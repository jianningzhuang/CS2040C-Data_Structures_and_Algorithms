#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  stack<int> s;
  int curr = 0;
  for (int i = 0; i < k; i++){
    string temp;
    cin >> temp;
    if (temp == "undo"){
      int undo;
      cin >> undo;
      for (int j = 0; j < undo; j++){
        s.pop();
      }
      if (s.empty()){
        curr = 0;
      }
      else{
        curr = s.top();
      }
    }
    else{
      int pos = stoi(temp);
      curr = (curr + pos)%n;
      if (curr < 0){
        curr += n;
      }
      //cout << curr << endl;
      s.push(curr);
    }
  }
  cout << curr;
}
