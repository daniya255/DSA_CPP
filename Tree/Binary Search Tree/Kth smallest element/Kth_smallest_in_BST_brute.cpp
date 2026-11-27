#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
void InOrder(TreeNode *node,vector<int>&values)
{
    if (node == nullptr)
        return;
    InOrder(node->left,values);
    values.push_back(node->val);
    InOrder(node->right,values);
}

int kthSmallest(TreeNode* root, int k){
    int ans;
    vector<int>values;
    InOrder(root,values);
    ans  = values[k-1];
    return ans;
}

int main() {
    // Constructing a sample binary search tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    int k = 2;
    
    // Calling the main function to get the result
    int ans = kthSmallest(root, k);
    
    // Printing the output
    cout << "Kth Smallest: " <<ans<< endl;
    
    return 0;
}