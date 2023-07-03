#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  stack<int> s;
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    if (s.empty()){
      s.push(temp);
    }
    else{
      if ((s.top()+temp)%2 == 0){
        s.pop();
      }
      else{
        s.push(temp);
      }
    }
  }
  int counter = 0;
  while (!s.empty()){
    counter++;
    s.pop();
  }
  cout << counter << endl;
}
