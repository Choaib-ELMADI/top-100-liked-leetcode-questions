#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0, end = nums.size();
            int mid = (start+end) / 2;

            int i=0;
            while (nums[mid] != target) {
                if (nums[mid] < target) {
                    start = mid;
                } else {
                    end = mid;
                }
                mid = (start+end)/2;

                ++i;
                if (i>(nums.size())/2) {
                    return -1;
                }
            }

            return mid;
        }
};

int main() {
    vector<int> nums = {2, 5, 6, 7, 8, 9, 11, 12};
    int target = 12;

    Solution test;
    cout << "Index of " << target << " = " << test.search(nums, target);
    cout << endl;

    return 0;
}