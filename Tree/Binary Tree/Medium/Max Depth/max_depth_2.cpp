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

int maxDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = maxDepth(root->left);

    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    int depth  = maxDepth(root);
    cout<<"Maximum depth is : "<<depth<<endl;
    return 0;
}

//Time Complexity : O(N), the algorithm visits and processes every single node in the tree exactly once
//Space Complexity : O(H) (where H is the height of the tree) 
