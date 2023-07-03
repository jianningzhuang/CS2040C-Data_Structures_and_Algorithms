#include <bits/stdc++.h>
using namespace std;

int main(){
  int counter = 0;
  string cmd;
  map<string, int> inandout;
  map<string, int> timespent;
  while (cin >> cmd){
    if (cmd == "OPEN"){
      counter++;
      cout << "Day " << counter << endl;
    }
    else if (cmd == "ENTER"){
      string name;
      int timein;
      cin >> name >> timein;
      inandout[name] = timein;
    }
    else if (cmd == "EXIT"){
      string name;
      int timeout;
      cin >> name >> timeout;
      timespent[name] += (timeout - inandout[name]);
      inandout.erase(name);
    }
    else if (cmd == "CLOSE"){
      for (auto it = timespent.begin(); it != timespent.end(); it++){
        double money = double((it->second))/10;
        cout << it->first << " $" << fixed << setprecision(2) << money << endl;
      }
      inandout.clear();
      timespent.clear();
      cout << endl;
    }
  }
}
