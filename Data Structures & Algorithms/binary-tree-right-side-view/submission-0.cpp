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
private :
    vector<int> ans;
public:
    void rightSideViewWithLvl(TreeNode* root,int lvl) {
        if(root == nullptr) return;
        if(ans.size()<= lvl ) ans.push_back(root->val);
        rightSideViewWithLvl(root->right,lvl+1);
        rightSideViewWithLvl(root->left,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        ans = {};
        rightSideViewWithLvl(root,0);
        return ans;
    }
};
