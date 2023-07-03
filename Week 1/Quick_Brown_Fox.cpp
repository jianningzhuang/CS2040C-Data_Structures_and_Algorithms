#include <iostream>
using namespace std;


void pangram(string phrase, int len){
  int arr[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (auto &c: phrase){
    if (isalpha(c)){
      int index = tolower(c) - 'a';
      arr[index] = 1;
    }
  }
  string result = "";
  for (int i = 0; i < 26; i++){
    if (arr[i] == 0){
      result += char(i + int('a'));
    }
  }
  if (result == ""){
    cout << "pangram\n";
  }
  else{
    cout << "missing " << result << endl;
  }
}

int main(){
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++){
    string phrase;
    getline(cin, phrase);
    pangram(phrase, phrase.length());
  }
}
