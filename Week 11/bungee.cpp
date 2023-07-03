#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> heights;
  for (int i = 0; i < n; i++){
    ll h;
    cin >> h;
    heights.push_back(h);
  }
  ll result = 0;
  ll curr = heights[0];
  set<ll> between;
  for (int i = 1; i < n; i++){
    if (heights[i] >= curr){
      if (!between.empty() && (curr - *between.begin()) > result){
        result = (curr - *between.begin());
      }
      curr = heights[i];
      between.clear();
    }
    else{
      between.insert(heights[i]);
    }
  }
  curr = heights[n-1];
  between.clear();
  for (int i = n-2; i >=0 ; i--){
    if (heights[i] >= curr){
      if (!between.empty() && (curr - *between.begin()) > result){
        result = (curr - *between.begin());
      }
      curr = heights[i];
      between.clear();
    }
    else{
      between.insert(heights[i]);
    }
  }
  cout << result << endl;
}
