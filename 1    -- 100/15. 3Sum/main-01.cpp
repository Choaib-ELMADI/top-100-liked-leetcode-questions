/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!                                       !!!
    !!!                O(n^3)                 !!!
    !!!                                       !!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

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
                int x=nums[i];

                for (int j=i+1; j<nums.size()-1; ++j) {
                    int y=nums[j];

                    for (int k=j+1; k<nums.size(); ++k) {
                        int z=nums[k];

                        if (x+y+z == 0) {
                            w.push_back({ x, y, z });
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