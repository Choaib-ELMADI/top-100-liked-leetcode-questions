#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    TreeNode(): 
        val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x): 
        val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right): 
        val(x), left(left), right(right) {}

    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (root == nullptr) return true;

            queue<TreeNode *> q;
            q.push(root);

            while (!q.empty()) {
                int size = q.size();
                vector<int> values;

                for (int i=0; i<size; ++i) {
                    TreeNode *curr = q.front();
                    q.pop();

                    if (curr != nullptr) {
                        values.push_back(curr->val);
                        q.push(curr->left);
                        q.push(curr->right);
                    } else {
                        values.push_back(INT_MIN);
                    }
                }

                vector<int> reversedValues = values;
                reverse(reversedValues.begin(), reversedValues.end());

                if (values != reversedValues) {
                    return false;
                }
            }

            return true;
        }
};

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(4);

    Solution test;
    bool isTreeSymmetric = test.isSymmetric(root);
    cout << boolalpha;
    cout << "isTreeSymmetric = " << isTreeSymmetric << endl;

    return 0;
}