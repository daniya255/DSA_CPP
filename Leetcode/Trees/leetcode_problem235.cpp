/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            // If both p and q are smaller, go left
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If both p and q are larger, go right
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Otherwise, this node is the split point (LCA)
            else {
                return root;
            }
        }
        return nullptr;
    }
};