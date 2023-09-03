#include <iostream>
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
        int maxDepth(TreeNode *root) {
            if (root == nullptr) return 0;

            int n = 1, m = 1;

            int a = maxDepth(root->left);
            n += a;
            int b = maxDepth(root->right);
            m += b;

            return (n > m ? n : m);
        }
};

int main() {
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    root->right->right->left = new TreeNode(7);

    Solution test;
    int n = test.maxDepth(root);
    cout << "Maximum depth = " << n << endl;

    return 0;
}