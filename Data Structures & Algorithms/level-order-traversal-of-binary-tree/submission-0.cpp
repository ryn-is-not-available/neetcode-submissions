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
private:
    vector<vector<int>> ans;
public:
    void levelOrderWithlevels(TreeNode* root,int level){
        if(root == nullptr) return;
        if(ans.size()-1<level) ans.push_back({});
        ans[level].push_back(root->val);
        levelOrderWithlevels(root->left,level+1);
        levelOrderWithlevels(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return ans;
        ans.push_back({});
        levelOrderWithlevels(root,0);
        return ans;
    }
};
