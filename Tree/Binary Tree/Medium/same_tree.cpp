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

bool isSameTree(TreeNode* p, TreeNode* q) {
    stack<pair<TreeNode*,TreeNode*>> st;
    st.push({p,q});

    while(!st.empty()){
        TreeNode* nodeA = st.top().first;
        TreeNode* nodeB = st.top().second;
        st.pop();

        if (nodeA == NULL && nodeB == NULL) {
            continue;
        }

        if (nodeA == NULL || nodeB == NULL) {
            return false;
        }

        if (nodeA->val != nodeB->val) {
            return false;
        }

        st.push({nodeA->right, nodeB->right});
        st.push({nodeA->left, nodeB->left});
    }
       return true; 
}
int main(){
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    bool ans = isSameTree(root1,root2);
    (ans) ? cout<<"True" : cout<<"False" ;
    cout<<endl;
    
    return 0;
}

//Time Complexity: O(N)
//Space Complexity : O(H) where H is the height