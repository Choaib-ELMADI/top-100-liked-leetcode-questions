#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            for(int i=1; i<nums.size(); ++i) {
                nums[i] = max(nums[i] + i, nums[i-1]);
            }

            int j = 0;
            int jumps = 0;
            while(j < nums.size()-1) {
                ++jumps;
                j = nums[j];
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