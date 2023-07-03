#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> palindrome;
  for (int i = 100; i < 1000; i++){
    int temp = i;
    int result = i;
    result = result*10 + temp%10;
    temp = temp/10;
    result = result*10 + temp%10;
    temp = temp/10;
    result = result*10 + temp%10;
    palindrome.insert(result);
  }
  for (int i = 0; i < n; i++){
    int num;
    cin >> num;
    if (num == 100000){
      cout << 100001 << endl;
      continue;
    }
    auto it = palindrome.upper_bound(num);
    int upp = *it;
    it--;
    int low = *it;
    cout << upp << low << endl;
    if ((upp - num) < (num-low)){
      cout << upp << endl;
    }
    else{
      cout << low << endl;
    }
  }
}
