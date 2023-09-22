#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string result = strs[0];

            for (int i{1}; i<strs.size(); ++i) {
                int j = 0;
                while (strs[i].find(result)) {
                    if (j == strs[0].length()) {
                        return "";
                    }
                    result.pop_back();
                    j++;
                }
            }

            return result;
        }
};

int main() {
    Solution test;
    vector<string> strs = { "carlight", "cargo", "car" };
    string res = test.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << res << endl;

    return 0;
}