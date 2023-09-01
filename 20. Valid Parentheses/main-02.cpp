#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
    public:
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
};

int main() {
    Solution test;
    string s = "()[({)]";
    bool res = test.isValid(s);

    cout << boolalpha;
    cout << "Is " << s << " valid? ==> " << res << endl;

    return 0;
}
