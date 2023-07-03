#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std; 

typedef tree<string, null_type, less<string>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

int main(){
  int n;
  new_data_set male;
  new_data_set female;
  while (cin >> n && n != 0){
    if (n == 1){
      string name;
      int gender;
      cin >> name >> gender;
      if (gender == 1){
        male.insert(name);
      }
      else{
        female.insert(name);
      }
    }
    else if (n == 2){
      string name;
      cin >> name;
      if (male.find(name) != male.end()){
        male.erase(name);
      }
      if (female.find(name) != female.end()){
        female.erase(name);
      }
    }
    else if (n == 3){
      string start, end;
      int type;
      int result = 0;
      if (type == 0){
        cout << *(male.find_by_order(1));
        // result += int(female.upper_bound(end) - female.lower_bound(start));
      }
      else if (type == 1){
        // result += int(male.upper_bound(end) - male.lower_bound(start));
      }
      else if (type == 2){
        // result += int(female.upper_bound(end) - female.lower_bound(start));
      }
      cout << result << endl;
    }
  }
}
