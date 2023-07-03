#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld numberfy(string name){
  ld result = 0;
  int count = 0;
  for (auto &c : name){
    result += double(int(c))/16;
    result *= 10;
    count++;
  }
  for (int i = 0; i < 10-count; i++){
    result *= 10;
  }
  ld max = 1;
  for (int i = 0; i < 11; i++){
    max *= 10;
  }
  result = max - result;
  for (int i = 0; i < 12; i++){
    result /= 10;
  }
  return result;
}


int main(){
  ll n, k;
  cin >> n >> k;
  priority_queue<pair<ld, string>> pq;
  unordered_set<string> dead;
  unordered_set<string> treated;
  for (int i = 0; i < n; i++){
    int q;
    cin >> q;
    if (q == 1){
      ll time, severity;
      string name;
      cin >> time >> name >> severity;
      ld priority = severity - k*time;
      priority *= 100;
      priority += numberfy(name);
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
            treated.insert(name);
            pq.pop();
            found = true;
          }
          else{
            if (pq.empty()){
              cout << "doctor takes a break\n";
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
