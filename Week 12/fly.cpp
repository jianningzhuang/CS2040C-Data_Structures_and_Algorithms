#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

unordered_set<ll> board;
vector<int> dr = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dc = {1, -1, 1, -1, 2, -2, 2, -2};
vector<int> mr;
vector<int> mc;
vector<pair<int, int>> moveset;
unordered_map<ll, ll> parent;

bool findpiece(int x, int y){
  for (auto it = moveset.begin(); it != moveset.end(); it++){
    if (it->first == x && it->second == y){
      return true;
    }
  }
  return false;
}

void genmoveset(){
  vector<pair<int, int>> frontier;
  frontier.push_back({0, 0});
  for (int i = 0; i < 3; i++){
    vector<pair<int, int>> next;
    for (auto &u : frontier){
      for (int j = 0; j < 8; j++){
        int tempx = u.first + dr[j];
        int tempy = u.second + dc[j];
        if (!findpiece(tempx, tempy)){
          next.push_back({tempx, tempy});
          moveset.push_back({tempx, tempy});
        }
      }
    }
    frontier = next;
  }
}

int bfs(ll rs, ll cs, ll rt, ll ct){
  int result = -1;
  queue<pair<ll, ll>> pq;
  pq.push({rs, cs});
  parent[rs*2000000001+cs] = 0;
  while (!pq.empty()){
    pair<ll, ll> u = pq.front();
    pq.pop();
    ll i = u.first;
    ll j = u.second;
    //cout << i << j << endl;
    if (i == rt && j == ct){
      result++;
      while (parent[i*2000000001 + j] != 0){
        result++;
        ll ii = parent[i*2000000001 + j]/2000000001;
        ll jj = parent[i*2000000001 + j]%2000000001;
        i = ii;
        j = jj;
      }
      return result;
    }
    for (auto it = moveset.begin(); it != moveset.end(); it++){
      ll rr = i + it->first;
      ll cc = j + it->second;
      if (rr >= 1 && rr <= 2000000000 && cc >= 1 && cc < 2000000000){
        if (parent.find(rr*2000000001 + cc) == parent.end() && board.find(rr*2000000001 + cc) != board.end()){
          cout << rr << " , " << cc << endl;
          parent[rr*2000000001 + cc] = i*2000000001 + j;
          pq.push({rr, cc});
        }
      }
    }
  }
  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  ll xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  for (int i = 0; i < n; i++){
    ll x, y;
    cin >> x >> y;
    board.insert(x*2000000001+y);
  }
  genmoveset();
  cout << bfs(xs, ys, xt, yt) << endl;
}
