#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

int getLeftHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left; 
    }
    return height;
}

int getRightHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right; 
    }
    return height;
}

int countNodes(TreeNode* root){
    int leftHeight = getLeftHeight(root);
    int rightHeight = getRightHeight(root);
    
    if (leftHeight == rightHeight) return ((1<<leftHeight) - 1 );

    return 1 + countNodes(root->left) + countNodes(root->right);
}