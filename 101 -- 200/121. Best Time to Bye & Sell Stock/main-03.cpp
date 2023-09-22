#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.empty()) return 0;

            int minPrice = prices[0];
            int maxProfit = 0;

            for (int i=1; i<prices.size(); ++i) {
                if (prices[i] < minPrice) minPrice = prices[i];
                else {
                    int profit = prices[i] - minPrice;
                    if (profit > maxProfit) maxProfit = profit;
                }
            }

            return maxProfit;
        }
};

int main() {
    Solution test;
    vector<int> prices = {7,1,5,3,6,4};

    int max = test.maxProfit(prices);
    cout << "Max profit: " << max << endl;

    return 0;
}