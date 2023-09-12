#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int distEnd = 0;

            for (int i=nums.size()-distEnd-1; i>=0; --i) {
                int curr = nums[i];

                if (curr) {
                    ++distEnd;
                } else {
                    int k=0;
                    for (int j=0; j<distEnd; ++j) {
                        int temp = nums[i+k];
                        nums[i+k] = nums[i+k+1];
                        nums[i+k+1] = temp;
                        ++k;
                    }
                }
            }
        }
};

int main() {
    vector<int> v = {1, 2, -1, 0, 3, 0, 4, -2, 0};

    for (auto n: v) cout << n << "  ";
    cout << endl;

    Solution test;
    test.moveZeroes(v);

    for (auto n: v) cout << n << "  ";
    cout << endl;

    return 0;
}