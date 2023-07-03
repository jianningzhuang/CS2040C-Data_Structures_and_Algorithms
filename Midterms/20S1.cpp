#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> A = {5,7,3,10,4};
  int best = 0;
  for (int i = 0; i < 5; i++){
	   int weakest = 11;
	    for (int j = 0; j < 3; j++){
		      if (weakest == 11 || A[(i+j)%5] < weakest){
			      weakest = A[(i+j)%5];
		        }
	         }
	      if (best == 0 || weakest > best){
		best = weakest;
	}
}
cout << best;

}
