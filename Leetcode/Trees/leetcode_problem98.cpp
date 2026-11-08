/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool helper(TreeNode* node, TreeNode*& prev) {
        if (node == NULL)
            return true;

        if (!helper(node->left, prev))
            return false;

        if (prev != NULL && node->val <= prev->val)
            return false;

        prev = node;

        return helper(node->right, prev);
    }

public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return helper(root, prev);
    }
};