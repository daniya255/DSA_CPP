#include <bits./stdc++.h>
using namespace std;

class Node
{ // Node structure for the binary tree
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    { // Constructor to initialize node
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{ // Binary Tree Class
private:
    Node *root;

    void inorderTraversal(Node *node)
    { // Recursive inorder traversal function
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(Node *node)
    {
        if (root == nullptr)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void preorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    bool searchNode(Node* node, int key){
        if(node == nullptr) return false;
        if(node->data == key) return true;
        return searchNode(node->left,key) || searchNode(node->right,key);
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int data)
    { // Function to insert data in level-order (simple binary tree, not based on value)
        Node *newNode = new Node(data);
        if (root == nullptr)
        { // If the tree is empty, set the new node as the root
            root = newNode;
            return;
        }
        queue<Node *> q; // Use a queue for level-order traversal to find the first available position
        q.push(root);
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            // Check the left child
            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            else
            {
                q.push(current->left);
            }

            // Check the right child
            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }

    void inorder()
    { // Function to perform inorder traversal (left -> root -> right)
        inorderTraversal(root);
        cout << endl;
    }

    void postorder()
    {
        postorderTraversal(root);
        cout << endl;
    }

    void preorder()
    {
        preorderTraversal(root);
        cout << endl;
    }

    bool search(int key) {
        return searchNode(root, key);
    }
};

int main()
{
    BinaryTree tree;
    // Insert values into the binary tree in level-order
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    cout << "Inorder Traversal: ";
    tree.inorder();

    return 0;
}