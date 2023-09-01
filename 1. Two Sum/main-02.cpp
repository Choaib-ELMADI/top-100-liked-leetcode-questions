#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans;

            for (int i{}; i<nums.size(); ++i) {
                int a = nums[i];

                for (int j{i+1}; j<nums.size(); ++j) {
                    if (a+nums[j] == target) {
                        ans.push_back(i);
                        ans.push_back(j);
                        break;
                    }
                }
                if (ans.size() == 2) {
                    break;
                }
            }

            return ans;
        }
};

int main() {
    vector<int> v = { 1, 4, 5, 8 };
    int target = 6;

    Solution test;
    vector<int> ans = test.twoSum(v, target);

    for (auto num: ans) {
        cout << num << " ";
    }
    cout << endl << target << endl;

    return 0;
}