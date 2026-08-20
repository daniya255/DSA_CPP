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

Node *del_nth_node(Node *head, int n)
{
    // Edge case: empty list
    if (head == nullptr)
        return head;
    if (head->next == nullptr)
    {
        if (n == 1)
            return nullptr;
        else
            return head;
    }

    Node *slow = head;
    Node *fast = head;

    //Give 'fast' an N-step head start
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    //If fast reached nullptr, it means N is equal to the length of the list,
    // so we need to remove the head node
    if (fast == nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    //Move both fast and slow together until fast reaches the last node
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //'slow' is now right before the node we want to remove. Bypass it
    Node *nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return head;

}

int main()
{
    vector<int> arr={1,3,2,5,4};
    Node* head=convertArr2LL(arr);
    head=del_nth_node(head,3);
    print(head);
    return 0;
}

// Time Complexity: O(N), since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
// Space Complexity: O(1), constant additional space is used to check unique elements.