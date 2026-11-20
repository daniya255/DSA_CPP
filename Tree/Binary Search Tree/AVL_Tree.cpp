#include<bits/stdc++.h>
using namespace std;
class AVL{
    struct Node{
        int val;
        int height;
        Node* left;
        Node* right;

        Node(int key) : val(key) , left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node){
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node){
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node* node){
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* rightRotate(Node* x){
        Node* y = x->left;
        Node* T2 = y->right;

        y->right = x;
        x->left = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* removeNode(Node* node,int key){
        if (node == nullptr) return nullptr;

        if(key < node->val) node->left = removeNode(node->left,key);
        else if (key > node->val) node->right = removeNode(node->right,key);
        else{
            if(node->left == nullptr){
                Node* temp = node->right;
                delete node;
                return balance(temp);
            }
            if(node->right == nullptr){
                Node* temp = node->left;
                delete node;
                return balance(temp);
            }

            Node* temp = minVal(node->right);
            node->val = temp->val;
            node->right = removeNode(node->right,temp->val);
            
        }
        return balance(node);
    }

    Node* insertNode(Node* node, int key){
        if (node == nullptr) return new Node(key);
        if(key < node->val) node->left = insertNode(node->left,key);
        else if (key > node->val) node->right = insertNode(node->right,key);
        else return node;

        return balance(node);
    }

    Node* balance(Node* node){
        if(node == nullptr) return nullptr;
        updateHeight(node);

        int balanceFac = balanceFactor(node);

        if(balanceFac > 1){
            if(balanceFactor(node->left) < 0){
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
        }

        if(balanceFac < -1 ){
            if(balanceFactor(node->right) > 0) {
                node->right = rightRotate(node->right);
            }
            return leftRotate(node);
        }

        return node; //if node is balanced 

    }

    Node* minVal(Node* node){
        Node* curr = node;
        while(curr != NULL && curr->left != NULL) curr = curr->left;
        return curr;
    }

    void inorder(Node* node){
        if (node == nullptr) return;
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }

    public:
        AVL() : root(nullptr) {}
        void insert(int key) {
            root = insertNode(root,key);
        }
        void remove(int key){
            root = removeNode(root,key);
        }
        void inorderTraversal(){
            inorder(root);
        }


};
int main(){
    return 0;
}