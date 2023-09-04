#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max = 0;

            for (int i=0; i<prices.size(); ++i) {
                for (int j=i+1; j<prices.size(); ++j) {
                    int temp = prices[j]-prices[i];

                    if (temp < 0) continue;
                    
                    if (temp > max) {
                        max = temp;
                    }
                }
            }

            return max;
        }
};

int main() {
    Solution test;
    vector<int> prices = {7,1,5,3,6,4};

    int max = test.maxProfit(prices);
    cout << "Max profit: " << max << endl;

    return 0;
}