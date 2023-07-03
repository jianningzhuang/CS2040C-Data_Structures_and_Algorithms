#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> v = {"Jianning", "Tommy", "Alex", "alex"};
	sort(v.begin(), v.end(), [](string a, string b){return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());});
	for (auto i = v.begin(); i != v.end(); i++){
		cout << *i << endl;
	}

}
