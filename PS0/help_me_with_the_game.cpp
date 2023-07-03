#include <bits/stdc++.h>
using namespace std;

bool compare_white(string a, string b){
  map<char, int> order;
  order['K'] = 0;
  order['Q'] = 1;
  order['R'] = 2;
  order['B'] = 3;
  order['N'] = 4;
  order['P'] = 5;
  if(order[a[0]] == order[b[0]]){
    if (a[2] == b[2]){
      return a[1] < b[1];
    }
    return a[2] < b[2];
  }
  return order[a[0]] < order[b[0]];
}
bool compare_black(string a, string b){
  map<char, int> order;
  order['K'] = 0;
  order['Q'] = 1;
  order['R'] = 2;
  order['B'] = 3;
  order['N'] = 4;
  order['P'] = 5;
  if(order[a[0]] == order[b[0]]){
    if (a[2] == b[2]){
      return a[1] < b[1];
    }
    return a[2] > b[2];
  }
  return order[a[0]] < order[b[0]];
}

// bool increasing_row(string a, string b){
//   return (a[2] < b[2]);
// }
// bool decreasing_row(string a, string b){
//   return (a[2] > b[2]);
// }
// bool increasing_col(string a, string b){
//   return (a[1] < b[1]);
// }

string print_white(vector<string> &v){
  string result = "";
  sort(v.begin(), v.end(), compare_white);
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'K'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'Q'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'R'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'B'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'N'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'P'){
      string temp = *i;
      temp.erase(temp.begin());
      result += temp;
      result += ',';
    }
  }
  if (result != ""){
    result.pop_back();
  }
  return result;
}

string print_black(vector<string> &v){
  string result = "";
  sort(v.begin(), v.end(), compare_black);
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'K'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'Q'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'R'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'B'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'N'){
      result += *i;
      result += ',';
    }
  }
  for (auto i = v.begin(); i != v.end(); i++){
    if ((*i)[0] == 'P'){
      string temp = *i;
      temp.erase(temp.begin());
      result += temp;
      result += ',';
    }
  }
  if (result != ""){
    result.pop_back();
  }
  return result;
}

int main(){
  vector<string> white;
  vector<string> black;
  for (int i = 1; i <= 17; i++){
    string line;
    getline(cin, line);
    int col = -1;
    for (auto &c: line){
      if (c == '|'){
        col++;
      }
      if (c == 'K' || c == 'Q' || c == 'R' || c == 'B' || c == 'N' || c == 'P'){
        string piece = "";
        piece += c;
        piece += char(col + int('a'));
        piece += to_string(9-i/2);
        white.push_back(piece);
      }
      if (c == 'k' || c == 'q' || c == 'r' || c == 'b' || c == 'n' || c == 'p'){
        string piece = "";
        piece += toupper(c);
        piece += char(col + int('a'));
        piece += to_string(9-i/2);
        black.push_back(piece);
      }
    }
  }
  cout << "White: " << print_white(white) << endl;
  cout << "Black: " << print_black(black);
}
