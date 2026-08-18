#include <bits/stdc++.h>
using namespace std;
// Node class to represent each node in the linked list
class Node
{
public:
    int data;
    Node *next; // Pointer to the next node

    // Constructor with data and next pointer
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    // Constructor with only data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to print the linked list
void print(Node *head)
{

    // edge case : if linked list is empty
    if (head == NULL)
        return;

    Node *temp = head;

    // traverse till the tail of the linked list to connect nodes together
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// converts an arr/vector to a linked list and return a pointer to the head
Node *convertArr2LL(vector<int> arr)
{

    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

bool isPalindrome(Node *head)
{

    if (head->next == nullptr)
        return true;

    // Create an empty stack to store values
    stack<int> nodes;

    // Initialize a temporary pointer to the head of the linked list
    Node *temp = head;

    // Traverse the linked list and push values onto the stack
    while (temp != nullptr)
    {
        nodes.push(temp->data); // push the current node's data into stack
        temp = temp->next;      // move the pointer to the next node
    }

    // re-initialize the pointer to the head of the linked list
    temp = head;

    // Compare values by popping from the stack and checking against linked list nodes
    while (temp != nullptr)
    {

        // If values don't match, it's not a palindrome
        if (temp->data != nodes.top())
            return false;

        temp = temp->next; // move the pointer to the next node
        nodes.pop();       // remove the previous node's data from the stack, so the next node data can be on top
    }

    // return true if loop is terminated, meaning the linked list is a plaindrome
    return true;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(9);

    // Print the original linked list
    cout << "Original Linked List: ";
    print(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

/*
Time Complexity: O(N), we traverse the entire linked list twice, once to push all elements into the stack, and once to compare them with the original list.
Space Complexity: O(N), we use a stack that stores all the elements of the linked list, which takes linear space in the worst case.
*/