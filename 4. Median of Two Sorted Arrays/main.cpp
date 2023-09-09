#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> nums;
            int start1=0, start2=0;

            while (start1 < nums1.size() && start2 < nums2.size()) {
                if (nums1[start1] < nums2[start2]) {
                    nums.push_back(nums1[start1]);
                    ++start1;
                } else {
                    nums.push_back(nums2[start2]);
                    ++start2;
                }
            }
            while (start1 < nums1.size()) {
                nums.push_back(nums1[start1]);
                ++start1;
            }
            while (start2 < nums2.size()) {
                nums.push_back(nums2[start2]);
                ++start2;
            }
        
            int start=0, end=nums.size();
            int size=nums.size();
            double mid;
            while (start < end) {
                if (size % 2) {
                    mid = *(nums.begin() + start);
                } else {
                    mid = ((double)*(nums.begin() + start) + (double)*(nums.begin() + start + 1)) / 2;
                }

                ++start;
                --end;
            }

            return mid;
        }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution test;
    double mid = test.findMedianSortedArrays(nums1, nums2);
    cout << "Midian = " << mid << endl;

    return 0;
}