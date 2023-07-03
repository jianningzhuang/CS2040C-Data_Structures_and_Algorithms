#include <bits/stdc++.h>
using namespace std;

void printword(vector<vector<int>> &order, vector<string> &words, int start){
  cout << words[start];
  for (auto &p : order[start]){
    printword(order, words, p);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> words;
  for (int i = 0; i < n; i++){
    string word;
    cin >> word;
    words.push_back(word);
  }
  if (n == 1){
    cout << words[0];
    return 0;
  }
  vector<vector<int>> order(n);
  int start = -1;
  for (int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    order[a].push_back(b);
    if (start == -1 || start == b){
      start = a;
    }
  }
  printword(order, words, start);
}
