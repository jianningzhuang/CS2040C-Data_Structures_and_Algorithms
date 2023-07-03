#include <bits/stdc++.h>
using namespace std;

int main(){
  string line;
  map<string, set<string>> projects;
  string title;
  while (getline(cin, line) && line != "0"){
    if (line == "1"){
      set<string> students;
      set<string> duplicates;
      for (auto it = projects.begin(); it != projects.end(); it++){
        for (auto is = (it->second).begin(); is != (it->second).end(); is++){
          if (students.find(*is) != students.end()){
            duplicates.insert(*is);
          }
          else{
            students.insert(*is);
          }
        }
      }
      for (auto it = projects.begin(); it != projects.end(); it++){
        set<string> &s = it->second;
        for (auto is = duplicates.begin(); is != duplicates.end(); is++){
          if (s.find(*is) != s.end()){
            s.erase(*is);
          }
        }
      }
      map<int, set<string>> output;
      for (auto it = projects.begin(); it != projects.end(); it++){
        output[(it->second).size()].insert(it->first);
      }
      for (auto it = output.rbegin(); it != output.rend(); it++){
        for (auto is = (it->second).begin(); is != (it->second).end(); is++){
          cout << *is << " " << it->first << endl;
        }
      }
      projects.clear();
    }
    else if (isupper(line[0])){
      title = line;
      projects[title] = {};
    }
    else{
      projects[title].insert(line);
    }
  }
}
