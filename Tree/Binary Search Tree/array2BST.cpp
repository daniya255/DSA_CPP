#include<bits/stdc++.h>
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
TreeNode* sorting (vector<int>&nums,int left,int right){
    if(left > right) return nullptr;
    int mid  = left + ( right - left + 1)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sorting(nums,left,mid-1);
    root->right = sorting(nums,mid+1,right);

    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    int left = 0;
    int right = nums.size() - 1;
    return sorting(nums,left,right);
}

void levelOrder(TreeNode* root){
    if(!root) return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);

        cout<<curr->val<<" ";
    }
}
int main(){
    return 0;
}