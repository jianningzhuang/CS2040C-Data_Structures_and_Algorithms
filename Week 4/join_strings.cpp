#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  vector<list<string>> all_words;
  for (int i = 0; i < N; i++){
    string word;
    cin >> word;
    list<string> w;
    w.push_back(word);
    all_words.push_back(w);
  }
  int last = 0;
  for (int i = 0; i < N-1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    all_words[a].splice(all_words[a].end(), all_words[b]);
    last = a;
  }
  for (string &s : all_words[last]){
    cout << s;
  }
  cout << endl;
}
