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
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;

        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        TreeNode* leftmost = rightChild;
        while (leftmost->left != NULL)
            leftmost = leftmost->left;
        leftmost->left = leftChild;

        return rightChild;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;

        if (key == root->val) {
            return helper(root);
        }

        TreeNode* current = root;
        while (current != nullptr) {
            // Target is smaller, so it must be on the left side
            if (current->val > key) {
                // If the immediate left child is the target, replace it
                if (current->left != nullptr && current->left->val == key) {
                    current->left = helper(current->left);
                    break;
                } else {
                    // Otherwise, take a step down to the left
                    current = current->left;
                }
            }
            // Target is larger, so it must be on the right side
            else {
                // If the immediate right child is the target, replace it
                if (current->right != nullptr && current->right->val == key) {
                    current->right = helper(current->right);
                    break;
                } else {
                    // Otherwise, take a step down to the right
                    current = current->right;
                }
            }
        }
        return root;
    }
};