#include <bits/stdc++.h>
using namespace std;


void transpose(string m[], int len){
  for (int i = 0; i < len; i++){
    for (int j = i; j < len; j++){
      int temp;
      temp = m[i][j];
      m[i][j] = m[j][i];
      m[j][i] = temp;
    }
  }
}

void reverse_row(string m[], int len){
  for (int i = 0; i < len; i++){
    reverse(m[i].begin(), m[i].end());
  }
}


int main(){
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++){
    string line;
    getline(cin, line);
    int size = ceil(sqrt(line.length()));
    string matrix[size];
    string::iterator it = line.begin();
    for (int a = 0; a < size; a++){
      string row = "";
      for (int b = 0; b < size; b++){
        if (it == line.end()){
          row += '*';
        }
        else{
          row += *it;
          it++;
        }
      }
      matrix[a] = row;
    }
    transpose(matrix, size);
    reverse_row(matrix, size);
    string result = "";
    for (int a = 0; a < size; a++){
      for (int b = 0; b < size; b++){
        if (matrix[a][b] != '*'){
          result += matrix[a][b];
        }
      }
    }
    cout << result << endl;
  }
}
