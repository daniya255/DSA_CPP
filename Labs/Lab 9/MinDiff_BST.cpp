#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (node == nullptr) return;

        inorder(node->left);

        if (prev != nullptr) {
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node;

        inorder(node->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        minDiff = INT_MAX;
        prev = nullptr;
        inorder(root);
        return minDiff;
    }
};