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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<TreeNode*>q;
    TreeNode *node = root;
    bool left2right = true;
    q.push(node);

    while(!q.empty()){
        int size = q.size();
        vector<int>level;

        for (int i=0; i<size; i++){
            TreeNode* temp = q.front();
            q.pop();
            level.push_back(temp->val);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        if (!left2right)  reverse(level.begin(),level.end());

        ans.push_back(level);

        left2right = !left2right;
    }

    return ans;
}
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>>ans;
    ans = zigzagLevelOrder(root);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//Time Complexity :O(N) + O(N) =  O(N) :
//-->every single node in the tree is pushed into the queue once and popped from the queue once.
//-->For any given level with K nodes, collecting them takesO(K) time, and reversing them takes O(K)time. If you sum the sizes of all levels across the entire tree , it equals N
//Space Complexity : O(N)(due to the queue memory and the output storage).