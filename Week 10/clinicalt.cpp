#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;

//start 09:26


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  map<ll, set<string>> clinic;
  unordered_set<string> dead;
  for (int i = 0; i < n; i++){
    int q;
    cin >> q;
    if (q == 1){
      ll t, s;
      string name;
      cin >> t >> name >> s;
      ll priority = (s - k*t);
      clinic[priority].insert(name);
    }
    else if (q == 2){
      ll t;
      cin >> t;
      if (clinic.empty()){
        cout << "doctor takes a break\n";
      }
      else{
        bool found = false;
        while (!found){
          set<string> curr = clinic.rbegin()->second;
          ll p = clinic.rbegin()->first;
          if (clinic.empty()){
            cout << "doctor takes a break\n";
            break;
          }
          else if (dead.find(*(curr.begin())) != dead.end()){
            curr.erase(curr.begin());
            if (curr.empty()){
              clinic.erase(p);
              curr = clinic.rbegin()->second;
            }
          }
          else{
            cout << *(curr.begin()) << endl;
            found = true;
            curr.erase(curr.begin());
            if (curr.empty()){
              clinic.erase(p);
              curr = clinic.rbegin()->second;
            }
            break;
          }
        }
      }
    }
    else if (q == 3){
      ll t;
      string name;
      cin >> t >> name;
      dead.insert(name);
    }
  }
}
