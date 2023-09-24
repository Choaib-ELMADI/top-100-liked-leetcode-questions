#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return;

            int i=1, lastInc=-1;  //==> Search for some right peak
            while (i<n) {
                if (nums[i] > nums[i-1]) {
                    lastInc = i;
                }
                ++i;
            }

            if (lastInc == -1) {  //==> If nums is in descending order
                for (i=0; i<n/2; ++i) {
                    swap(nums[i], nums[n-i-1]); //==> swap nums
                }
                return;
            }

            int peak = nums[lastInc], index = lastInc;
            for (i=lastInc; i<n; ++i) {
                if (nums[i] > nums[lastInc-1] && nums[i] < nums[index]) {
                    index = i;
                }
            }
            swap(nums[lastInc-1], nums[index]);
            sort(nums.begin()+lastInc, nums.end());
        }
};

int main() {
    vector<int> v = {1, 2, 3};
    Solution test;
    test.nextPermutation(v);

    for (int a:v) {
        cout << a << " - ";
    }
    cout << endl;

    return 0;
}