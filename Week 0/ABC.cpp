#include <iostream>
using namespace std;

void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void sort(int *a, int *b, int *c){
  if (*a > *b){
    swap(a, b);
  }
  if (*a > *c){
    swap(a, c);
  }
  if (*b > *c){
    swap(b, c);
  }
}


int main(){
  int a, b, c;
  cin >> a >> b >> c;
  string order;
  cin >> order;
  sort(&a, &b, &c);
  for (int i = 0; i < 3; i++){
    if (order[i] == 'A'){
      cout << a << " ";
    }
    else if (order[i] == 'B'){
      cout << b << " ";
    }
    else if (order[i] == 'C'){
      cout << c << " ";
    }
  }

}
