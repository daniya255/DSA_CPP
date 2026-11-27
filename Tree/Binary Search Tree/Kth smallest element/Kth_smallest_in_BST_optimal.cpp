#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int countSmallest = 0;
    int kthSmallestVal = -1;

    void findSmallest(TreeNode* root, int k) {
        if (root == NULL || countSmallest >= k) {
            return;
        }
        
        // Process left subtree first
        findSmallest(root->left, k);
        
        // Increment count and check if current node is the target
        countSmallest++;
        if (countSmallest == k) {
            kthSmallestVal = root->val;
            return;
        }
        
        // Process right subtree
        findSmallest(root->right, k);
    }

public:
    // Main function to coordinate both traversals
    int findKthElements(TreeNode* root, int k) {
        findSmallest(root, k);
    
        return kthSmallestVal;
    }
};

// Driver code starts here
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    
    Solution obj;
    int k = 3;
    
    int result = obj.findKthElements(root, k);
    
    cout << "Kth Smallest: " << result << endl;
    
    return 0;
}