#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        void backTracking(int n, int open, int close, vector<string>& v, string s) {
            if (open == close && close == n) {
                v.push_back(s);
                return;
            }

            if (open < n) {
                s.push_back('(');
                backTracking(n, open+1, close, v, s);
                s.pop_back();
            }

            if (close < open) {
                s.push_back(')');
                backTracking(n, open, close+1, v, s);
                s.pop_back();
            }
        }

        vector<string> generateParenthesis(int n) {
            vector<string> v;
            string s = "";

            backTracking(n, 0, 0, v, s);

            return v;
        }
};

int main() {
    int n = 1;

    Solution test;
    vector<string> v = test.generateParenthesis(n);

    for (string s:v) {
        cout << s << " - ";
    }
    cout << endl;

    return 0;
}