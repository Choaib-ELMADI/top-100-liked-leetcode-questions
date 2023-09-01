#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>&);

int main() {
    vector<string> strs = { "car", "clow", "cloght" };
    string res = longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << res << endl;

    return 0;
}

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