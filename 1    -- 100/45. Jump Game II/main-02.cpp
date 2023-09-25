#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int jumps = 0;
            int left = 0, right = 0;

            while (right < nums.size() - 1) {
                int far = 0;
                for (int i=left; i<=right; ++i) {
                    far = max(far, i+nums[i]);
                }

                left = right + 1;
                right = far;
                ++jumps;
            }

            return jumps;
        }
};

int main() {
    vector<int> v={2,3,1,1,4};
    Solution test;

    int minJ = test.jump(v);
    cout << "Minimum jumps to reach end = " << minJ << endl;

    return 0;
}