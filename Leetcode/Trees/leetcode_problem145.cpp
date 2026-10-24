/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<TreeNode*> postorder;
        TreeNode* node = root;

        while (node != NULL || !postorder.empty()) {
            if (node != NULL) {
                postorder.push(node);
                node = node->left;
            } else {
                TreeNode* temp = postorder.top()->right;
                if (temp == NULL) {
                    temp = postorder.top();
                    postorder.pop();
                    ans.push_back(temp->val);
                    while (!postorder.empty() &&
                           temp == postorder.top()->right) {
                        temp = postorder.top();
                        postorder.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    node = temp;
                }
            }
        }

        return ans;
    }
};