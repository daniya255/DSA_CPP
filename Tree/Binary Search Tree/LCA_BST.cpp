#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
        // If both p and q are smaller, go left
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both p and q are larger, go right
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // Otherwise, this node is the split point (LCA)!
        else {
            return root;
        }
    }
    return nullptr;
}

int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << lca->val << endl;
    }
    return 0;
}

//Time Complexity: O(H), where H is the height of the tree. The loop runs once for each level it descends.
//Space Complexity: O(1), because we are only updating a single pointer and using no extra memory.
