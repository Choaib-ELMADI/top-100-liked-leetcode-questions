#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
    public:
        void inOrderTraversal(TreeNode *root, vector<int>& v) {
            if (root == nullptr) return;

            inOrderTraversal(root->left, v);
            v.push_back(root->val);
            inOrderTraversal(root->right, v);
        }
};

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution test;
    vector<int> v;
    test.inOrderTraversal(root, v);

    for (auto n: v) {
        cout << n << " - ";
    }
    cout << endl;

    return 0;
}