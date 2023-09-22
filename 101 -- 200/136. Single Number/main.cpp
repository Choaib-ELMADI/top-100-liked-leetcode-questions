/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!                                     !!!
    !!!            XOR OPERATOR             !!!
    !!!                                     !!!
    !!!            a ^ a ==> 0              !!!
    !!!                                     !!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int single = 0;
            
            for (int i=0; i<nums.size(); ++i) {
                single = single^nums[i];
            }

            return single;
        }
};

int main() {
    Solution test;
    vector<int> v = {2, 1, 4, 1, 2};

    int single = test.singleNumber(v);
    cout << "Single number = " << single << endl;

    return 0;
}