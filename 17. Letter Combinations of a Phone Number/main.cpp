#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> result;
            if (digits.empty()) {
                return result;
            }
            
            generateCombinations(digits, "", 0, result);
            return result;
        }

    private:
        map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        void generateCombinations(string& digits, string current, int index, vector<string>& result) {
            if (index == digits.length()) {
                result.push_back(current);
                return;
            }

            char currChar = digits[index];
            string currStr = m[currChar];

            for (char c:currStr) {
                generateCombinations(digits, current+c, index+1, result);
            }
        }
};


int main() {
    string digits = "23";

    Solution test;
    vector<string> v = test.letterCombinations(digits);

    for (auto s:v) {
        cout << s << endl;
    }

    return 0;
}