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
public:
    int DFS(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftDepth = DFS(root->left);
        if (leftDepth == -1)
            return -1;
        int rightDepth = DFS(root->right);
        if (rightDepth == -1)
            return -1;

        if (abs(leftDepth - rightDepth) > 1)
            return -1;
        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) { return DFS(root) != -1; }
};