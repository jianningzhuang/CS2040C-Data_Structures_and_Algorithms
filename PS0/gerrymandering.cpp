#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<pair<int, int>> &v){
  for (auto i = v.begin(); i != v.end(); i++){
    cout << i->first << i->second << endl;
  }
}

int main(){
  int p, d;
  cin >> p >> d;
  vector<pair<int, int>> districts;
  for (int i = 0; i < d; i++){
    districts.push_back(pair<int,int>(0,0));
  }
  for (int i = 0; i < p; i++){
    int di, a, b;
    cin >> di >> a >> b;
    districts[di - 1].first += a;
    districts[di - 1].second += b;
  }
  int v = 0;
  int wasted_a = 0;
  int wasted_b = 0;
  for (int i = 0; i < d; i++){
    int total = districts[i].first + districts[i].second;
    v += total;
    int majority = (total/2 + 1);
    if (districts[i].first > districts[i].second){
      wasted_a += districts[i].first - majority;
      wasted_b += districts[i].second;
      cout << "A " << districts[i].first - majority << " " << districts[i].second << endl;
    }
    else{
      wasted_a += districts[i].first;
      wasted_b += districts[i].second - majority;
      cout << "B " << districts[i].first << " " << districts[i].second - majority << endl;
    }
  }
  double gap = abs(double(wasted_a - wasted_b))/double(v);
  cout << gap;
}
