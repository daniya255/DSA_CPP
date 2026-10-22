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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr) return ans;
    stack<TreeNode *> preorder;
    TreeNode *node = root;
    preorder.push(node);
        while(!preorder.empty()) {
            node = preorder.top();
            preorder.pop();
            ans.push_back(node->val);
            if(node->right) preorder.push(node->right);
            if(node->left) preorder.push(node->left);
        }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    vector<int> ans = preorderTraversal(root);
    for(int node: ans) cout<<node<<" ";

        return 0;
}