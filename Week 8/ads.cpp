#include <bits/stdc++.h>
using namespace std;

//start 3:47 to

void printimg(vector<vector<char>> v, int h, int w){
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << v[i][j];
    }
    cout << endl;
  }
}

vector<int> borders(vector<vector<char>> &v, int x, int y, int h, int w){
  vector<int> result;
  result.push_back(x);
  result.push_back(y);
  int width = y;
  int height = x + 1;
  while (width < w && v[x][width] == '+'){
    v[x][width] = '-';
    width++;
  }
  while (height < h && v[height][y] == '+'){
    v[height][y] = '-';
    height++;
  }
  width--;
  height--;
  result.push_back(width);
  result.push_back(height);
  // cout << x << y << height << width << endl;
  while (x <= height){
    v[x][width] = '-';
    x++;
  }
  while (y <= width){
    v[height][y] = '-';
    y++;
  }
  return result;
}

void scanad(vector<vector<char>> &v, vector<int> b, int h, int w){
  for (int i = b[0]; i <= b[3]; i++){
    for (int j = b[1]; j <= b[2]; j++){
      if (v[i][j] == '?' || v[i][j] == '!' || v[i][j] == ',' || v[i][j] == '.' || v[i][j] == ' ' || isalnum(v[i][j])){
        continue;
      }
      else{
        for (int m = b[0]; m <= b[3]; m++){
          for (int n = b[1]; n <= b[2]; n++){
            v[m][n] = ' ';
          }
        }
        return;
      }
    }
  }
}


int main(){
  int h, w;
  cin >> h >> w;
  cin.ignore();
  vector<vector<char>> v(h);
  for (int i = 0; i < h; i++){
    string line;
    getline(cin, line);
    for (auto &c : line){
      v[i].push_back(c);
    }
  }
  vector<vector<int>> images;  //keep track of borders
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (v[i][j] == '+'){
        vector<int> temp;
        temp = borders(v, i, j, h, w);
        images.push_back(temp);
        printimg(v, h, w);
      }
    }
  }
  while (!images.empty()){
    int largest = 0;
    vector<int> r;
    for (int i = 0; i < images.size(); i++){
      if ((images[i][0] + images[i][1]) > largest){
        largest = (images[i][0] + images[i][1]);
        r = images[i];
      }
    }
    scanad(v, r, h, w);
    vector<vector<int>>::iterator it = images.begin();
    while (*it != r){
      it++;
    }
    images.erase(it);
  }
  printimg(v, h, w);
}
