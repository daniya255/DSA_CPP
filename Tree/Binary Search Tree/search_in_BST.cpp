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

TreeNode* searchBST(TreeNode* root, int val){
    while(root!= NULL && root->val!= val){
        root = val < root->val ? root->left : root->right ;
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
    int val = 7;
    TreeNode* node = searchBST(root,val);
    (node != NULL) ? cout<<node->val<<endl : cout<<"Node not found";
    return 0;
}