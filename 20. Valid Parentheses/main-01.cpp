#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string);

int main() {
    bool res = isValid("(]");

    cout << boolalpha;
    cout << "isValid = " << res << endl;

    return 0;
}

bool isValid(string s) {
    stack<char> opening;

    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') {
            opening.push(c);
        } else {
            if (opening.empty()) return false;
            
            char openParen = opening.top();
            opening.pop();
            
            if ((c == ')' && openParen != '(') ||
                (c == ']' && openParen != '[') ||
                (c == '}' && openParen != '{')) {
                return false;
            }
        }
    }

    return opening.empty();
}