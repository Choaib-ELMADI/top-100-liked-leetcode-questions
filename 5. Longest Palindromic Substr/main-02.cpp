#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.length() <= 1) return s;

            int maxLength = 1;
            int n = s.length();
            int start = 0, end = 0;
            
            for (int i=0; i<n; ++i) {
                auto expandPalindrome = [&](int left, int right) {
                    while (left >= 0 && right < n && s[left] == s[right]) {
                        left--;
                        right++;
                    }

                    int len = right - left - 1;
                    if (len > maxLength) {
                        maxLength = len;
                        start = left + 1;
                        end = right - 1;
                    }
                };

                expandPalindrome(i, i);

                if (i<n-1 && s[i] == s[i + 1]) {
                    expandPalindrome(i, i + 1);
                }
            }
            
            return s.substr(start, maxLength);        
        }
};

int main() {
    string s = "hellollehowoh";

    Solution test;
    string longestPalSubStr = test.longestPalindrome(s);

    cout << "Longest palindrome is " << longestPalSubStr << endl;

    return 0;
}