class Solution {
private:
    int maxDiameter = 0;

    int height(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};