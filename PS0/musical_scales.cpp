#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<string> notes = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
  set<string> sequence;
  for (int i = 0; i < n; i++){
    string note;
    cin >> note;
    sequence.insert(note);
  }
  string result = "";
  for (int i = 0; i < 12; i++){
    int s = i;
    set<string> scale;
    scale.insert(notes[s%12]);
    scale.insert(notes[(s+2)%12]);
    scale.insert(notes[(s+4)%12]);
    scale.insert(notes[(s+5)%12]);
    scale.insert(notes[(s+7)%12]);
    scale.insert(notes[(s+9)%12]);
    scale.insert(notes[(s+11)%12]);
    if (includes(scale.begin(), scale.end(), sequence.begin(), sequence.end())){
      result += notes[i];
      result += ' ';
    }
  }
  if (result == ""){
    cout << "none\n";
  }
  else{
    cout << result << endl;
  }
}
