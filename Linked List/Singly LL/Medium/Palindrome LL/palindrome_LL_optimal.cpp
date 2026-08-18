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

Node *reverseLL(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prev = NULL;

    // Start from the head of the list
    Node *curr = head;

    // Traverse the list
    while (curr != NULL)
    {
        // Save the next node
        Node *front = curr->next;

        // Reverse the current node's pointer
        curr->next = prev;

        // Move prev to current node
        prev = curr;

        // Move to the next node
        curr = front;
    }

    // Return new head (last node becomes first)
    return prev;
}

Node *middleNode(Node *head)
{
    // If the list is empty or has only
    // one element, return the head asit's the middle.
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *slow = head;  //move pointer one step ahead
    Node *fast = head->next;    //move pointer two steps ahead

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool isPalindrome(Node *head)
{

    if (head->next == nullptr)
        return true;

    Node *mid = middleNode(head);

    // Reverse the second half of the linked list starting from the middle
    Node *newHead = reverseLL(mid->next);

    // Pointer to the reversed second half
    Node *second = newHead;

    // Pointer to the first half
    Node *first = head;

    // Compare data values of nodes from both halves
    while (second != nullptr)
    {
        // If values do not match, the list is not a palindrome
        if (first->data != second->data)
        {
            reverseLL(newHead); // Reverse the second half back to its original state
            return false;
        }
        first = first->next;
        second = second->next;
    }
    
    // Reverse the second half back to its original state
    reverseLL(newHead);
    return true;
}

int main()
{
    // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

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
Time Complexity: O(N), we traverse the list four times, once to reverse half of it, once to compare, once to find the middle node, and once to restore the original list, which simplifies to O(N).
Space Complexity: O(1), no extra space is used apart from a few pointers; operations are done in-place.
*/