#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* node,long long min_val,long long max_val){
    if(node == NULL) return true;

    if(node->val<=min_val || node->val>=max_val) return false;

    return helper(node->left,min_val,node->val) && helper(node->right,node->val,max_val);
}

bool isValidBST(TreeNode* root){
    return helper(root,LLONG_MIN,LLONG_MAX);
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
//Space Complexity: O(H), where H is the height of the tree, because of the memory used by the recursion stack.