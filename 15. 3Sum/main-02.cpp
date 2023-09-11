#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> w;
            sort(nums.begin(), nums.end());

            for (int i=0; i<nums.size()-2; ++i) {
                if (i==0 || nums[i] != nums[i-1]) {
                    int target = -nums[i];
                    int s=i+1, e=nums.size()-1;

                    while (s < e) {
                        if (target == nums[s]+nums[e]) {
                            w.push_back({ -target, nums[s], nums[e] });
                            while (s < e && nums[s] == nums[s+1]) ++s;
                            while (s < e && nums[e] == nums[e+1]) --e;
                            ++s; --e;
                        } else if (nums[s]+nums[e] < target) {
                            ++s;
                        } else {
                            --e;
                        }
                    }
                }
            }

            return w;
        }
};

int main() {
    vector<int> v = { -1,0,1,2,-1,-4 };

    Solution test;
    vector<vector<int>> w = test.threeSum(v);

    for (vector<int> a: w) {
        int i = 1;
        for (int n: a) {
            cout << setw(2) << n;
            i%3 ? cout << "  + " : cout << "  =  0" << endl;
            ++i;
        }
    }

    return 0;
}