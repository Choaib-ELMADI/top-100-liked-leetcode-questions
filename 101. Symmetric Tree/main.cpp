#include <iostream>
#include <queue>
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

            do {
                if (root->left != nullptr && root->right != nullptr) {
                    q.push(root->left);
                    q.push(root->right);
                } else {
                    return false;
                }

                TreeNode *first = q.front();
                q.pop();
                TreeNode *second = q.front();
                q.pop();

                if (first->left != nullptr && second->right != nullptr) {
                    q.push(first->left);
                    q.push(second->right);
                } else {
                    if (first->val != second->val) return false;
                    return true;
                }
            } while (!q.empty());

            return true;
        }
};

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution test;
    bool isTreeSymmetric = test.isSymmetric(root);
    cout << boolalpha;
    cout << "isTreeSymmetric = " << isTreeSymmetric << endl;

    return 0;
}