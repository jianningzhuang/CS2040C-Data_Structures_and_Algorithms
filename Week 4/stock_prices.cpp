#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++){
    int n;
    cin >> n;
    cin.ignore();
    priority_queue<int, vector<int>, greater<int>> sell;
    priority_queue<int> buy;
    int stock_price = -1;
    for (int j = 0; j < n; j++){
      string line;
      getline(cin, line);
      vector<string> tokens;
      stringstream ss(line);
      string token;
      string ask, bid, sto;
      while (getline(ss, token, ' ')){
        tokens.push_back(token);
      }
      if (tokens[0] == "buy"){
        for (int k = 0; k < stoi(tokens[1]); k++){
          buy.push(stoi(tokens[4]));
        }
        while (!sell.empty() && !buy.empty() && buy.top() >= sell.top()){
          stock_price = sell.top();
          buy.pop();
          sell.pop();
        }
        if (stock_price == -1){
          sto = "-";
        }
        else{
          sto = to_string(stock_price);
        }
        if (buy.empty()){
          bid = "-";
        }
        else{
          bid = to_string(buy.top());
        }
        if (sell.empty()){
          ask = "-";
        }
        else{
          ask = to_string(sell.top());
        }
        cout << ask << " " << bid << " " << sto << endl;
      }
      else{
        for (int k = 0; k < stoi(tokens[1]); k++){
          sell.push(stoi(tokens[4]));
        }
        while (!buy.empty() && !sell.empty() && buy.top() >= sell.top()){
          stock_price = sell.top();
          buy.pop();
          sell.pop();
        }
        if (stock_price == -1){
          sto = "-";
        }
        else{
          sto = to_string(stock_price);
        }
        if (buy.empty()){
          bid = "-";
        }
        else{
          bid = to_string(buy.top());
        }
        if (sell.empty()){
          ask = "-";
        }
        else{
          ask = to_string(sell.top());
        }
        cout << ask << " " << bid << " " << sto << endl;
      }
    }
  }
}
