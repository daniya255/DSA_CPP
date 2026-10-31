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

int maxDepth(TreeNode *root)
{
    int depth=0;

    if (root == NULL)
        return depth;
    TreeNode *node = root;
    queue<TreeNode *> q;
    q.push(node);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        depth++;
    }
    return depth;
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


//Space Complexity: O(W) (where W is the maximum width of the tree)
//Time Complexity: O(N), the algorithm visits and processes every single node in the tree exactly once
