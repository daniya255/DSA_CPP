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
    int countSmallest = 0;
    int kthSmallestVal = -1;

    void findSmallest(TreeNode* root, int k) {
        if (root == NULL || countSmallest >= k) {
            return;
        }

        // Process left subtree first
        findSmallest(root->left, k);

        // Increment count and check if current node is the target
        countSmallest++;
        if (countSmallest == k) {
            kthSmallestVal = root->val;
            return;
        }

        // Process right subtree
        findSmallest(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        findSmallest(root, k);

        return kthSmallestVal;
    }
};