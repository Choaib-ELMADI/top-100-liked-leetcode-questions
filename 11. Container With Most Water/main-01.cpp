/*
    ! Time Limit Exceeded
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxArea = 0;

            for (int i=0; i<height.size(); ++i) {
                for (int j=0; j<height.size(); ++j) {
                    int currArea = (j-i) * min(height[i], height[j]);
                    maxArea = max(maxArea, currArea);
                }
            }

            return maxArea;
        }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution test;
    int max = test.maxArea(height);
    cout << "Max area = " << max << endl;

    return 0;
}