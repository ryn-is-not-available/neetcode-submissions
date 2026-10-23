/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return max({diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right),maxDepth(root->left)+maxDepth(root->right)});
    }
};
