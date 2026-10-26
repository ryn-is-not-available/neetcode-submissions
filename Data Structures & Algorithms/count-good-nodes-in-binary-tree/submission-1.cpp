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
    int GoodNodesWithMax(TreeNode* root, int currentMax) {
        if(root == nullptr) return 0;
        if(root->val >= currentMax) return 1 + GoodNodesWithMax(root->right,root->val)+GoodNodesWithMax(root->left,root->val);
        return GoodNodesWithMax(root->right,currentMax)+GoodNodesWithMax(root->left,currentMax);
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return GoodNodesWithMax(root,root->val);
    }
};
