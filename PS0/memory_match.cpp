#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int K;
  cin >> N;
  cin >> K;
  vector<bool> cards;
  cards.assign(N, false);
  map<string, int> pairs;
  int flipped = 0;
  for (int i = 0; i < K; i++){
    int c1, c2;
    string p1, p2;
    cin >> c1 >> c2 >> p1 >> p2;
    if (cards[c1 - 1] == false){
      cards[c1 - 1] = true;
      pairs.insert(pair<string, int>(p1, 0));
      pairs[p1] += 1;
    }
    if (cards[c2 - 1] == false){
      cards[c2 - 1] = true;
      pairs.insert(pair<string, int>(p2, 0));
      pairs[p2] += 1;
    }
    if (p1 == p2){
      flipped++;
    }
  }
  int result = 0;
  int doubles = 0;
  for (auto i = pairs.begin(); i != pairs.end(); i++){
    if (i->second == 2){
      doubles++;
    }
  }
  if (pairs.size() == N/2){
    for (auto i = pairs.begin(); i != pairs.end(); i++){
      if (i->second >= 1){
        result++;
      }
    }
  }
  else if (pairs.size() + 1 == N/2 && doubles == pairs.size()){
    result += N/2;
  }
  else{
    for (auto i = pairs.begin(); i != pairs.end(); i++){
      if (i->second == 2){
        result++;
      }
    }
  }
  cout << result - flipped << endl;
}
