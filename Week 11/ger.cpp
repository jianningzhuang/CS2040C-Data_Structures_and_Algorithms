#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, int> visited;
unordered_map<string, string> parent;
vector<string> path;

string target;
string message;
int len = -1;

void dfs(string u){
  visited[u] = 1;
  for (auto &v : adj[u]){
    if (visited[v] == 0){
      parent[v] = u;
      dfs(v);
    }
  }
}

void printpath(string t){
  path.push_back(t);
  len++;
  if (parent[t] == "-1"){
    cout << t << " sends " << message << endl;
    return;
  }
  else{
    printpath(parent[t]);
    cout << t << " receives " << message << " from " << parent[t] << endl;
  }
}

void complain(){
  cout << target << " says: Why can't we use Teams? :-(\n";
}

int main(){
  cout << "Who is sender?\n";
  string me;
  cin >> me;
  cout << "Who is the target?\n";
  cin >> target;
  cout << "What is the message?\n";
  cin >> message;
  cout << "What are the connections?\n";
  for (int i = 0; i < 2; i++){
    string start, end;
    cin >> start >> end;
    adj[start].push_back(end);
  }
  parent[me] = "-1";
  dfs(me);
  cout << endl;
  printpath(target);
  cout << endl;
  cout << "This took an effort of level " << len << endl;
  cout << endl;
  complain();
}
