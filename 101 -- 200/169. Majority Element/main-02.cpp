/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!                                          !!!
    !!!     This code is working in VSCode       !!!
    !!!           but not in LeetCode            !!!
    !!!             official website             !!!
    !!!                                          !!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            vector<int> numsCount(nums.size(), 0);

            for (int i=0; i<nums.size(); ++i) {
                numsCount[nums[i]]++;
            }

            auto majPtr = max_element(numsCount.begin(), numsCount.end());
            return distance(numsCount.begin(), majPtr);
        }
};

int main() {
    vector<int> v = { 1, 2, 3, 1, 2, 1, 2, 3, 8, 8, 8, 8, 8, 8, 8, 8 };

    Solution test;
    int m = test.majorityElement(v);
    cout << "Majority element = " << m << endl;

    return 0;
}