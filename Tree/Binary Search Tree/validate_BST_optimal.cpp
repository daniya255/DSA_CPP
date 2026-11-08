#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* node, TreeNode* &prev){
    if(node == NULL) return true;

    if(!helper(node->left,prev)) return false;
    
    if(prev!=NULL && node->val <= prev->val) return false;

    prev = node;

    return helper(node->right,prev);
}

bool isValidBST(TreeNode* root){
    TreeNode* prev = nullptr;
    return helper(root,prev);
}
int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    bool result = isValidBST(root);
    if (result) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}

//Time Complexity: O(N), where N is the total number of nodes in the tree, because we visit each node exactly once.
//Space Complexity: O(H), where H is the height of the tree, representing the memory used on the call stack during the recursion.