#include <bits/stdc++.h>
using namespace std;

string call_as(string name){
  vector<string> words;
  string current = "";
  for (auto &c : name){
    if (c == ' '){
      words.push_back(current);
      current = "";
    }
    else{
      current += c;
    }
  }
  words.push_back(current);
  if (words.size() == 4){
    return words[3] + " " + words[0];
  }
  else if (words.size() == 3){
    return words[1] + " " + words[2];
  }
  if (words.size() == 2){
    return words[0] + " " + words[1];
  }
}

// int main(){
//   cout << call_as("Ng Zhen Rui Matthew") << endl;
//   cout << call_as("Tan Jun An") << endl;
//   cout << call_as("Lim Li");
// }

// class module{
// private:
//   string code, name;
//   int max_quota;
//   vector<string> roster; //alphabetical unordered_map
// public:
//   module(string new_code, string new_name, int new_quota){
//     code = new_code;
//     name = new_name;
//     max_quota = new_quota;
//   }
//   string getDisplayName(){
//     return code + " - " + name;
//   }
//   int binary_string(string name, int low, int high){
//     if (low > high){
//       return -1;
//     }
//     int mid = (low + high)/2;
//     if (roster[mid] == name){
//       return mid;
//     }
//     else if (roster[mid] < name){
//       return binary_string(name, mid + 1, high);
//     }
//     else{
//       return binary_string(name, low, mid - 1);
//     }
//   }
//   int inClassRoster(string name){  // O(logn)
//     return binary_string(name, 0, roster.size() - 1);
//   }
//   void addStudent(string name){ //need shift so O(n) anyways?
//     if (roster.size() == max_quota){
//       return;
//     }
//     if (inClassRoster(name) != -1){
//       return;
//     }
//     if (roster.empty() || name > roster[roster.size() - 1]){
//       roster.push_back(name);
//       return;
//     }
//     int index;
//     if (name < roster[0]){
//       roster.insert(roster.begin(), name);
//     }
//     else{
//       for (int i = 0; i < roster.size() - 1; i++){
//         if (name > roster[i] && name < roster[i+1]){
//           index = i + 1;
//           roster.insert(roster.begin() + index, name);
//           return;
//         }
//       }
//     }
//   }
//   void dropStudent(string name){
//     if (inClassRoster(name) == -1){
//       return;
//     }
//     else{
//       int index = inClassRoster(name);
//       roster.erase(roster.begin() + index);
//     }
//   }
//   void printClassRoster(){
//     for (auto &s : roster){
//       cout << s << endl;
//     }
//     cout << "------\n";
//   }
// };
//
// int main(){
// module m("CS2040C", "Data Structures and Algorithms", 8); // quota 8
// cout << m.getDisplayName() << endl;
// m.addStudent("Ammar Fathin Sabili");
// m.addStudent("Ghozali Suhariyanto Hadi");
// m.addStudent("Sidhant Bansal");
// m.addStudent("Teh Nian Fei");
// m.addStudent("Mohideen Imran Khan");
// m.addStudent("Mohideen Imran Khan"); // will be denied, duplicate entry
// m.addStudent("Ler Wei Sheng");
// m.addStudent("Yohanes Yudhi Adhikusuma");
// m.addStudent("Srivastava Aaryam");
// m.printClassRoster(); // see the first set of printout
// m.addStudent("Steven Halim"); // will be rejected (9th student)
// m.printClassRoster(); // first and second set of printout are identical
// m.dropStudent("Yohanes Yudhi Adhikusuma");
// m.dropStudent("Sidhant Bansal");
// m.printClassRoster(); // see the third/last set of printout
// return 0;
// }
// typedef unsigned long long ll;
//
// void print_vector(vector<ll> &v){
//   for (auto i = v.begin(); i != v.end(); i++){
//     cout << *i << " ";
//   }
//   cout << endl;
// }
//
// bool compare(ll a, ll b){ //custom comparator swaps only if returns false
//   if (a%2 == 0 and b%2 == 0){
//     return a > b;
//   }
//   else if (a%2 == 1 and b%2 == 1){
//     return a < b;
//   }
//   else if (a%2 == 0 and b%2 == 1){
//     return true;
//   }
//   else{
//     return false;
//   }
// }
//
// int main(){
//   vector<ll> v = {1,3,2,4,5,6,7,5,7,2,1,2,9,6};
//   print_vector(v);
//   sort(v.begin(), v.end(), compare); //O(nlogn)
//   print_vector(v);
//
// }

int main(){
  int n;
  cin >> n;
  cin.get();
  vector<string> TA;
  for (int i = 0; i < n; i++){
    string name;
    getline(cin, name);
    TA.push_back(name);
  }
  sort(TA.begin(), TA.end(), [](string a, string b){return call_as(a) < call_as(b);});
  for (auto &v : TA){
    cout << call_as(v) << " (" << v << ")\n";
  }
}
