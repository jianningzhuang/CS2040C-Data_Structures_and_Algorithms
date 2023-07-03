#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  map<string, pair<int, int>> clinic;
  priority_queue<pair<ll, string>> queue;
  int num = 0;
  for (int i = 0; i < n; i++){
    int command;
    cin >> command;
    if (command == 0){
      string name;
      int level;
      cin >> name >> level;
      clinic[name] = {level, num};
      ll priority = level*1000000 + 200000 - num;
      num++;
      queue.push({priority, name});
    }
    else if (command == 1){
      string name;
      int increase;
      cin >> name >> increase;
      clinic[name].first += increase;
      ll priority = clinic[name].first*1000000 + 200000 - clinic[name].second;
      queue.push({priority, name});
    }
    else if (command == 2){
      string name;
      cin >> name;
      map<string, pair<int, int>>::iterator it = clinic.find(name);
      clinic.erase(it);
    }
    else if (command == 3){
      if (clinic.empty()){
        cout << "The clinic is empty\n";
      }
      else{
        bool found = false;
        while (!found){
          string name = queue.top().second;
          if (clinic.find(name) != clinic.end() && (clinic[name].first*1000000 + 200000 - clinic[name].second) == queue.top().first){
            cout << name <<  endl;
            found = true;
          }
          else{
            queue.pop();
          }
        }
      }
    }
  }
}
