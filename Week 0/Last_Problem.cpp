#include <iostream>
using namespace std;

// int main(){
//   char person_name[100];
//   cin.getline(person_name, sizeof(person_name));
//   cout << "Thank you, " << person_name << ", and farewell!\n";
// }

int main(){
  string name;
  getline(cin, name);
  cout << "Thank you, " << name << ", and farewell!\n";
}
