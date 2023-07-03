#include <bits/stdc++.h>
using namespace std;

void print_matrix(string m[], int len){
  for (int i = 0; i < len; i++){
    cout << m[i] << "\n";
  }
}

void reverse_row(string m[], int rows){
  for (int i = 0; i < rows; i++){
    reverse(m[i].begin(), m[i].end());
  }
}

void reverse_col(string m[], int cols, int rows){
  for (int i = 0; i < cols; i++){
    for (int j = 0; j < rows/2; j++){
      int temp;
      temp = m[j][i];
      m[j][i] = m[rows - 1 - j][i];
      m[rows - 1 - j][i] = temp;
    }
  }
}


int main(){
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++){
    int rows, cols;
    cin >> rows >> cols;
    cin.ignore();
    string matrix[rows];
    for (int a = 0; a < rows; a++){
      string line;
      getline(cin, line);
      matrix[a] = line;
    }
    reverse_row(matrix, rows);
    reverse_col(matrix, cols, rows);
    cout << "Test " << i << "\n";
    print_matrix(matrix, rows);
  }
}
