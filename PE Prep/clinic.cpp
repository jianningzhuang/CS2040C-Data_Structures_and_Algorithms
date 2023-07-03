#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;

//start 20:54

struct compare{
  bool operator()(pair<ll, string> p1, pair<ll, string> p2){
    if (p1.first == p2.first){
      return lexicographical_compare(p2.second.begin(), p2.second.end(), p1.second.begin(), p1.second.end()); //p2 smaller lexi
    }
    else{
      return p1.first < p2.first;  //p1 greater than p2 / decreasing order
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  priority_queue<pair<ll, string>, vector<pair<ll, string>>, compare> clinic;
  unordered_set<string> dead;
  for (int i = 0; i < n; i++){
    int q;
    cin >> q;
    if (q == 1){
      ll t, s;
      string name;
      cin >> t >> name >> s;
      ll priority = (s - k*t);
      clinic.push({priority, name});
    }
    else if (q == 2){
      ll t;
      cin >> t;
      if (clinic.empty()){
        cout << "doctor takes a break\n";
      }
      else{
        bool found = true;
        pair<ll, string> p = clinic.top();
        while (dead.find(p.second) != dead.end()){
          clinic.pop();
          if (clinic.empty()){
            cout << "doctor takes a break\n";
            found = false;
            break;
          }
          else{
            p = clinic.top();
          }
        }
        if (found){
          cout << p.second << endl;
          clinic.pop();
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
