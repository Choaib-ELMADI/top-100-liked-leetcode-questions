#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            auto left = height.begin();
            auto right = height.end() - 1;
            int maxArea = 0;

            while (left != right) {
                int currArea = (right-left) * min(*right, *left);
                maxArea = max(maxArea, currArea);

                if (*left < *right) {
                    ++left;
                } else {
                    --right;
                }
            }

            return maxArea;
        }
};

int main() {
    // vector<int> height = {1,7,2,3,5};
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    // vector<int> height = {1,2,1};

    Solution test;
    int max = test.maxArea(height);
    cout << "Max area = " << max << endl;

    return 0;
}