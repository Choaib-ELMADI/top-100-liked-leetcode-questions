#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int maj = 0;
            int count = 1;

            for (int i=1; i<nums.size(); ++i) {
                if (nums[i] == nums[maj]) {
                    count++;
                } else {
                    count--;
                    if (count == 0) {
                        maj = i;
                        count = 1;
                    }
                }
            }

            return nums[maj];
        }
};

int main() {
    vector<int> v = { 1, 2, 3, 1, 2, 1};

    Solution test;
    int m = test.majorityElement(v);
    cout << "Majority element = " << m << endl;

    return 0;
}