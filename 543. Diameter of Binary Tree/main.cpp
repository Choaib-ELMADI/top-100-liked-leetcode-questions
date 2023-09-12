#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): 
        val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x): 
        val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right): 
        val(x), left(left), right(right) {}
};

class Solution {
    public:
        int diameterOfBinaryTree(TreeNode *root) {
            if (!root) return 0;

            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            int throughRoot = leftHeight + rightHeight;

            int leftDiameter = diameterOfBinaryTree(root->left);
            int rightDiameter = diameterOfBinaryTree(root->right);


            return max(throughRoot, max(leftDiameter, rightDiameter));
        }

        int height(TreeNode *node) {
            if (!node) return 0;

            return 1 + max(height(node->left), height(node->right));
        }
};

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution test;
    int n = test.diameterOfBinaryTree(root);

    cout << "Diameter = " << n << endl;

    return 0;
}