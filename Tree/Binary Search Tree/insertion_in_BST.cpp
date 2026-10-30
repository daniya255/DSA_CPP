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

TreeNode* insertIntoBST(TreeNode* root, int val){
    if (root == NULL) return new TreeNode (val);
    TreeNode* temp = root;
    while(true){
        if (temp->val <= val){
            if (temp->right != NULL) temp = temp->right;
            else {
                temp->right = new TreeNode (val);
                break;
            }
        }
        else{
            if (temp->left != NULL) temp = temp->left;
            else{
                temp->left = new TreeNode (val);
                break;
            }
        }
    }

    return root;
}

int main(){
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(12);
    int val = 8;
    TreeNode* node = insertIntoBST(root,val);
    
    return 0;
}