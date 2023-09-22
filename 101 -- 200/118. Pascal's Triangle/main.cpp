#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> w ={{1}};

            for (int i=0; i<numRows-1; ++i) {
                vector<int> temp = w.back();
                temp.insert(temp.begin(), 0);
                temp.push_back(0);

                vector<int> v;
                for (int j=0; j<w.back().size()+1; ++j) {
                    v.push_back(temp[j]+temp[j+1]);
                }
                
                w.push_back(v);
            }

            return w;
        }
};

int main() {
    int numRows = 5;
    Solution test;

    vector<vector<int>> w = test.generate(numRows);

    for (auto v: w) {
        for (auto n: v) {
            cout << n << " - ";
        }
        cout << endl;
    }

    return 0;
}