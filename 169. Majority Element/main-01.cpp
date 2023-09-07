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
            int numsCount[nums.size()] = {};

            for (int i=0; i<nums.size(); ++i) {
                numsCount[nums[i]]++;
            }

            int *majPtr = max_element(numsCount, numsCount+nums.size());
            return distance(numsCount, majPtr);
        }
};

int main() {
    vector<int> v = { 1, 2, 3, 1, 2, 1, 2, 3 };

    Solution test;
    int m = test.majorityElement(v);
    cout << "Majority element = " << m << endl;

    return 0;
}