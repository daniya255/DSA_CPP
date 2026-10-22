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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> inorder;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            inorder.push(node);
            node = node->left;
        }
        else
        {
            if (inorder.empty())
                break;
            node = inorder.top();
            inorder.pop();
            ans.push_back(node->val);
            node = node->right;
        }
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
    vector<int> ans = inorderTraversal(root);
    for(int node: ans) cout<<node<<" ";

        return 0;
}