#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool lexicographic(string s1, string s2){
  int len1 = s1.length();
  int len2 = s2.length();
  if (len1 >= len2){
    for (int i = 0; i < len2; i++){
      if (int(s1[i]) < int(s2[i])){
        return true;
      }
      else if (int(s1[i]) > int(s2[i])){
        return false;
      }
    }
    return false;
  }
  else{
    for (int i = 0; i < len1; i++){
      if (int(s1[i]) < int(s2[i])){
        return true;
      }
      else if (int(s1[i]) > int(s2[i])){
        return false;
      }
    }
    return true;
  }
}

struct compare{
  bool operator()(pair<ll, string> p1, pair<ll, string> p2){
    if (p1.first == p2.first){
      return lexicographic(p2.second, p1.second);
    }
    else{
      return p1.first < p2.first;
    }
  }
};


// bool operator<(pair<ll, string> p1, pair<ll, string> p2){
//   if (p1.first == p2.first){
//     return lexicographic(p2.second, p1.second);
//   }
//   else{
//     return p1.first < p2.first;
//   }
// }


int main(){
  ll n, k;
  cin >> n >> k;
  priority_queue<pair<ld, string>, vector<pair<ld, string>>, compare> pq;
  unordered_set<string> dead;
  for (int i = 0; i < n; i++){
    int q;
    cin >> q;
    if (q == 1){
      ll time, severity;
      string name;
      cin >> time >> name >> severity;
      ld priority = severity - k*time;
      pq.push({priority, name});

    }
    else if (q == 2){
      ll time;
      cin >> time;
      if (pq.empty()){
        cout << "doctor takes a break\n";
      }
      else{
        bool found = false;
        while (!found){
          string name = pq.top().second;
          if (dead.find(name) == dead.end()){
            cout << name << endl;
            pq.pop();
            found = true;
          }
          else{
            if (pq.empty()){
              cout << "doctor takes a break\n";
              found = true;
            }
            else{
              pq.pop();
            }
          }
        }
      }
    }
    else if (q == 3){
      ll time;
      string name;
      cin >> time >> name;
      dead.insert(name);
    }
  }
}
