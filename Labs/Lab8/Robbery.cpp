#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // Helper function returns a pair: {money_if_robbed, money_if_not_robbed}
    pair<int, int> robSub(TreeNode* root) {

        if (!root) return {0, 0};


        pair<int, int> left = robSub(root->left);
        pair<int, int> right = robSub(root->right);

        int rob = root->val + left.second + right.second;

        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, not_rob};
    }

public:
    int rob(TreeNode* root) {
        pair<int, int> result = robSub(root);
        return max(result.first, result.second);
    }
};