#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode* root, int& maxDiameter){
    if (root == nullptr) return 0;
    int leftHeight = getHeight(root->left,maxDiameter);
    int rightHeight = getHeight(root->right,maxDiameter);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return 1 + max(leftHeight,rightHeight);

}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;

    int maxDiameter = 0;
    getHeight(root, maxDiameter);
    return maxDiameter;
    
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
 
    cout <<diameterOfBinaryTree(root)<< endl;
 
    return 0;
}