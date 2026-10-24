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
vector<vector<int>> PreInPostOrder(TreeNode *root)
{
    vector<int> pre, post, in;
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    stack<pair<TreeNode *, int>> st;
    TreeNode *node = root;
    st.push({node, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            it.second++;
            pre.push_back(it.first->val);
            st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            it.second++;
            in.push_back(it.first->val);
            st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->val);
        }
    }

    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);

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
    vector<vector<int>> ans = PreInPostOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}