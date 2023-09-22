#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string, map<char, int>);

int main() {
    map<char, int> romanToInteger;
    romanToInteger['I'] = 1;
    romanToInteger['V'] = 5;
    romanToInteger['X'] = 10;
    romanToInteger['L'] = 50;
    romanToInteger['C'] = 100;
    romanToInteger['D'] = 500;
    romanToInteger['M'] = 1000;

    int ans = romanToInt("MCMXCIV", romanToInteger);
    cout << "ans = " << ans << endl;

    return 0;
}

int romanToInt(string s, map<char, int> m) {
    int result = 0;

    int i=0, j=1;

    for (i, j; i<s.length(), j<=s.length(); ++i, ++j) {
        if (m[s[i]] >= m[s[j]]) result += m[s[i]];
        else {
            result += (m[s[j]] - m[s[i]]);
            i += 1;
            j += 1;
        }
    }

    return result;
}