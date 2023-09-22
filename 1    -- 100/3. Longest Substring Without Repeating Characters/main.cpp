#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> charSet;
            int maxLength = 0;
            int start = 0, end = 0;

            while (end < s.length()) {
                if (charSet.find(s[end]) == charSet.end()) {
                    charSet.insert(s[end]);
                    end++;
                    maxLength = max(maxLength, end - start);
                } else {
                    charSet.erase(s[start]);
                    start++;
                }
            }

            return maxLength;
        }
};

int main() {
    Solution test;
    string s = "Hellowing";

    int n = test.lengthOfLongestSubstring(s);
    cout << "Longest substring length = " << n << endl;

    return 0;
}