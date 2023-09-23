#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int s = height.size();
            if (s <= 2) return 0;

            int maxLeft = height[0], maxRight = height[s-1];
            vector<int> maxLefts(s), maxRights(s);

            for (int i=1; i<s; ++i) {
                maxLefts[i] = maxLeft;
                maxLeft = max(maxLeft, height[i]);
            }

            for (int i=s-2; i>=0; --i) {
                maxRights[i] = maxRight;
                maxRight = max(maxRight, height[i]);
            }

            int trapWater = 0;
            for (int i=1; i<s-1; ++i) {
                if (height[i] < maxLefts[i] && height[i] < maxRights[i]) {
                    trapWater += (min(maxLefts[i], maxRights[i]) - height[i]);
                }
            }

            return trapWater;
        }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution test;

    cout << "Max trapped water = " << test.trap(height) << endl;

    return 0;
}