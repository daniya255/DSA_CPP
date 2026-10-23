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

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr) return ans;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    TreeNode *node = root;
    s1.push(node);
    while(!s1.empty()){
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while(!s2.empty()) {
        node = s2.top();
        s2.pop();
        ans.push_back(node->val);
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
    vector<int> ans = postorderTraversal(root);
    for(int node: ans) cout<<node<<" ";

        return 0;
}