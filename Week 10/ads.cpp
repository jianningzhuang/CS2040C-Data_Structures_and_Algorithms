#include <bits/stdc++.h>
using namespace std;

//start 1947 to

vector<string> ad;
stack<vector<int>> img;
int h, w;

void printad(){
  for (int i = 0; i < h; i++){
    cout << ad[i] << endl;
  }
}

void border(int r, int c){
  int j = c;
  while (j < w && ad[r][j] == '+'){
    ad[r][j] = '-';
    j++;
  }
  j--;
  int i = r + 1;
  while (i < h && ad[i][c] == '+'){
    ad[i][c] = '-';
    i++;
  }
  i--;
  img.push({r, c, i, j});
  c++;
  while (c < w && ad[i][c] == '+'){
    ad[i][c] = '-';
    c++;
  }
  r++;
  while (r < h && ad[r][j] == '+'){
    ad[r][j] = '-';
    r++;
  }
//  printad();
}

void erase(int r, int c, int hi, int wi){
  for (int i = r; i <= hi; i++){
    for (int j = c; j <= wi; j++){
      ad[i][j] = ' ';
    }
  }
}

void rebuild(int r, int c, int hi, int wi){
  for (int i = r; i <= hi; i++){
    ad[i][c] = '+';
  }
  for (int i = c + 1; i <= wi; i++){
    ad[r][i] = '+';
  }
  for (int i = c + 1; i <= wi; i++){
    ad[hi][i] = '+';
  }
  for (int i = r + 1; i <= hi; i++){
    ad[i][wi] = '+';
  }
}

void process(int r, int c, int hi, int wi){
  for (int i = r + 1; i < hi; i++){
    for (int j = c + 1; j < wi; j++){
      if (ad[i][j] != '?' && ad[i][j] != '!' && ad[i][j] != ',' && ad[i][j] != '.' && ad[i][j] != ' ' && ad[i][j] != '+' && !isalnum(ad[i][j])){
        //cout << "ha" << ad[i][j] << "ha" << endl;
        erase(r, c, hi, wi);
        return;
      }
    }
  }
  rebuild(r, c, hi, wi);
}


int main(){
  cin >> h >> w;
  cin.ignore();
  for (int i = 0; i < h; i++){
    string line;
    getline(cin, line);
    ad.push_back(line);
  }
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (ad[i][j] == '+'){
        border(i, j);
      }
    }
  }
  while (!img.empty()){
    vector<int> curr = img.top();
    process(curr[0], curr[1], curr[2], curr[3]);
    img.pop();
  }
  printad();
}
