#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9;
int V;

int shortestpath(vector<vector<int>> AM, int u, int v, int k){
  cout << AM[1][0] << "hi\n";
  int sp[V][V][k+1];
  for (int e = 0; e <= k; e++){
    for (int i = 0; i < V; i++){
      for (int j = 0; j < V; j++){
        sp[i][j][e] = INF;
        if (e == 0 && i == j){
          sp[i][j][e] = 0;
        }
        if (e == 1 && AM[i][j] != INF){
          sp[i][j][e] = AM[i][j];
        }
        if (e > 1){
          for (int a = 0; a < V; a++){
            if (AM[i][a] != INF && i != a && j!= a && sp[a][j][e-1] != INF){
              sp[i][j][e] = min(sp[i][j][e], (AM[i][a] + sp[a][j][e-1]));
            }
          }
        }
      }
    }
  }
  return sp[u][v][k];
}

int main()
{
    /* Let us create the graph shown in above diagram*/
    V = 4;
    vector<vector<int>> graph = { {0, 2, 9, 15},
                        {INF, 0, 3, INF},
                        {1, INF, 0, 7},
                        {INF, INF, INF, 0}
                      };
    int u = 0, v = 3, k = 1;
    cout << shortestpath(graph, u, v, k);
    return 0;
}
