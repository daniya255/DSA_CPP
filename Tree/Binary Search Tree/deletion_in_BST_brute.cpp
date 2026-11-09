#include<bits/stdc++.h>
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
TreeNode* helper(TreeNode* root){
    if (root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;

    TreeNode* leftChild = root->left;
    TreeNode* rightChild = root->right;
    TreeNode* leftmost = rightChild;
    while(leftmost->left != NULL) leftmost = leftmost->left;
    leftmost->left = leftChild;

    return rightChild;
}
TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL) return root;

        if(key == root->val) {
            return helper(root);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            root->left = deleteNode(root->left,key);
        }

    return root;
}
// Helper function to print in-order traversal of the tree
void printInOrder(TreeNode* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int key = 3;
    TreeNode* result = deleteNode(root, key);

    cout << "In-order traversal: ";
    printInOrder(result);
    cout<<endl;
    return 0;
}