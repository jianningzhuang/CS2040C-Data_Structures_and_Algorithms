#include <iostream>
using namespace std;

int max(int a, int b, int c){
  if (a >= b && a >= c){
    return a;
  }
  if (b >= c && b >= a){
    return b;
  }
  if (c >= b && c >= a){
    return c;
  }
  return 0;
}

int main(){
  int n;
  cin >> n;
  int a_score = 0;
  int b_score = 0;
  int c_score = 0;
  string a_seq = "ABC";
  string b_seq = "BABC";
  string c_seq = "CCAABB";
  for (int i = 0; i < n; i++){
    char current;
    cin >> current;
    if (current == a_seq[i%3]){
      a_score += 1;
    }
    if (current == b_seq[i%4]){
      b_score += 1;
    }
    if (current == c_seq[i%6]){
      c_score += 1;
    }
  }
  int max_score = max(a_score, b_score, c_score);
  cout << max_score << "\n";
  if (max_score == a_score){
    cout << "Adrian\n";
  }
  if (max_score == b_score){
    cout << "Bruno\n";
  }
  if (max_score == c_score){
    cout << "Goran\n";
  }
}
