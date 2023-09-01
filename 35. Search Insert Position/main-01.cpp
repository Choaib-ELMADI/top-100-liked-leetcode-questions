#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchInsert(vector<int>&, int);

int main() {
    int target = 5;
    vector<int> nums = {1, 2, 5, 7};

    int pos = searchInsert(nums, target);
    cout << "Position = " << pos << endl;

    return 0;
}

int searchInsert(vector<int>& nums, int target) {
    int start=0, end=nums.size(), mid=(start+end)/2;

    if (count(nums.begin(), nums.end(), target)) {
        while (nums[mid] != target) {
            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
            mid=(start+end)/2;
        }

        return mid;
    } else {
        if (nums[nums.size() - 1] < target) return nums.size();

        int i=0;
        while (true) {
            if (nums[i]>target) {
                return i;
            }
            ++i;
        }
    }
}