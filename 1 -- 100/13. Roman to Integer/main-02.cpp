#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int result = 0;

            int i=0, j=1;

            for (i, j; i<s.length(), j<=s.length(); ++i, ++j) {
                if (m[s[i]] >= m[s[j]]) result += m[s[i]];
                else {
                    result += (m[s[j]] - m[s[i]]);
                    ++i;
                    ++j;
                }
            }

            return result;
        }

    public:
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
};

int main() {
    Solution test;
    string s = "MCMXCIV";
    int ans = test.romanToInt(s);
    cout << s << " = " << ans << endl;

    return 0;
}