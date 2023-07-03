// #include <bits/stdc++.h>
// using namespace std;
//
// int main(){
//   string parantheses;
//   cin >> parantheses;
//   stack<char> s;
//   for (auto &c: parantheses){
//     if (c == '(' || c == '{' || c == '['){
//       s.push(c);
//     }
//     switch (c){
//       case ')':
//         char temp = s.top();
//         s.pop();
//         if (temp != '('){
//           cout << "not balanced\n";
//           return 0;
//         }
//         break;
//       case '}':
//         char temp = s.top();
//         s.pop();
//         if (temp != '{'){
//           cout << "not balanced\n";
//           return 0;
//         }
//         break;
//       case ']':
//         char temp = s.top();
//         s.pop();
//         if (temp != '['){
//           cout << "not balanced\n";
//           return 0;
//         }
//         break;
//     }
//     if (s.empty()){
//       cout << "balanced\n";
//     }
//   }
// }

#include <bits/stdc++.h>
using namespace std;

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i]) {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

// Driver program to test above function
int main()
{
    string expr = "{()}[]";

    if (areParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
