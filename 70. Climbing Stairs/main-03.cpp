#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int climbingStairs(int n) {
            if (n <= 1) return n;

            vector<int> countWays(n+1, 0);
            countWays[0] = countWays[1] = 1;
            
            for (int i=2; i<=n; ++i) {
                countWays[i] = countWays[i-1] + countWays[i-2];
            }

            return countWays[n];
        }
};

int main() {
    int n = 45;

    Solution test;
    int ways = test.climbingStairs(n);
    cout << "There is " << ways << " differente way(s)" << endl;

    return 0;
}