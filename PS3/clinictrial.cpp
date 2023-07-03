#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double numberfy(string name){
  double result = 0;
  int count = 0;
  for (auto &c : name){
    result += int(toupper(c)) - int('A');
    result *= 26;
    count++;
  }
  for (int i = 0; i < 10-count; i++){
    result *= 26;
  }
  double max = 1;
  for (int i = 0; i < 11; i++){
    max *= 26;
  }
  result = max - result;
  for (int i = 0; i < 16; i++){
    result /= 10;
  }
  return result;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  priority_queue<pair<double, string>> pq;
  unordered_set<string> patients;
  for (int i = 0; i < n; i++){
    int q;
    cin >> q;
    if (q == 1){
      ll time, severity;
      string name;
      cin >> time >> name >> severity;
      double priority = severity - k*time + numberfy(name);
      pq.push({priority, name});
      patients.insert(name);

    }
    else if (q == 2){
      ll time;
      cin >> time;
      if (patients.empty()){
        cout << "doctor takes a break\n";
      }
      else{
        bool found = false;
        string name = pq.top().second;
        while (!found){
          if (patients.find(name) != patients.end()){
            cout << name << endl;
            pq.pop();
            unordered_set<string>::iterator it = patients.find(name);
            patients.erase(it);
            cout << patients.size() << endl;
            found = true;
          }
          else{
            pq.pop();
            name = pq.top().second;
          }
        }
      }
    }
    else if (q == 3){
      ll time;
      string name;
      cin >> time >> name;
      unordered_set<string>::iterator it = patients.find(name);
      patients.erase(it);
    }
  }
}
