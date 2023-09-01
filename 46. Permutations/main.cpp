#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permute(vector<int>);

int main() {
    vector<int> v = { 1, 2, 3 };
    vector<vector<int>> w = permute(v);

    cout << "size of w = " << w.size() << endl;
    for (auto vec: w) {
        for (auto num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> permute(vector<int> v) {
    if (v.size() <= 1) return { v };

    vector<vector<int>> w;

    for (size_t i{}; i<v.size(); ++i) {
        vector<int> a(v.begin(), v.end());
        a.erase(a.begin() + i);

        vector<vector<int>> res = permute(a);

        for (size_t j{}; j<res.size(); ++j) {
            vector<int> b = res[j];
            b.insert(b.begin(), v[i]);
            w.push_back(b);
        }
    }

    return w;
}