#include <bits/stdc++.h>
using namespace std;
struct Point {
int x, y; // x and y coordinates of a point
};
struct Rectangle {
Point l, r; //Bottom-left of Rectangle, Top-right of Rectangle
};
// overlap should return True if rectangles A and B (passed as parameters) overlap,
// otherwise, it should return False.
bool overlap (Rectangle A, Rectangle B) {
// PS: A.r.x is the x-coordinate of rectangle A’s top-right point
  if (A.l.x > B.l.x && A.l.x < B.r.x && A.l.y > B.l.y && A.l.y < B.r.y){
    return true;
  }
  if (A.r.x > B.l.x && A.r.x < B.r.x && A.r.y > B.l.y && A.r.y < B.r.y){
    return true;
  }
  if (A.r.x > B.l.x && A.r.x < B.r.x && A.l.y > B.l.y && A.l.y < B.r.y){
    return true;
  }
  if (A.l.x > B.l.x && A.l.x < B.r.x && A.r.y > B.l.y && A.r.y < B.r.y){
    return true;
  }
  return false;
}

vector<vector<int>> adj;
vector<int> dist;
const int INF = 1e9;

int main() {
int N, S, T;
Rectangle rect[2000];
cin >> N; //N is the number of rectangles
for (int i = 0; i < N; i++) {
cin >> rect[i].l.x >> rect[i].l.y >> rect[i].r.x >> rect[i].r.y ;
}
cin >> S >> T; //Information needs to be transferred from entity S to entity T.
adj.assign(N, vector<int>());
for (int i = 0; i < N - 1; i++){
  for (int j = i + 1; j < N; j++){
    if (overlap(rect[i], rect[j])){
      adj[i].push_back(j);
      adj[j].push_back(i);
      cout << i << j << endl;
    }
  }
}
dist.assign(N, INF);
dist[S] = 0;
int layer = -1;
queue<int> q;
q.push(S);
while (!q.empty()){
  int u = q.front();
  q.pop();
  if (u == T){
    cout << dist[u] * 3 << endl;
    return 0;
  }
  if (dist[u] != layer){
    layer = dist[u];
  }
  for (auto &v : adj[u]){
    if (dist[v] == INF){
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}
cout << "impossible\n";
}

// int main() {
// int N, count = 0;
// Rectangle rect[2000];
// cin >> N; //N is the number of rectangles
// for (int i = 0; i < N; i++) {
// cin >> rect[i].l.x >> rect[i].l.y >> rect[i].r.x >> rect[i].r.y ;
// for (int k = 0; k < i; k++) {
// if (overlap(rect[k], rect[i])) count++;
// }
// }
// cout << "Number of Overlaps: " << count << endl;
// }
