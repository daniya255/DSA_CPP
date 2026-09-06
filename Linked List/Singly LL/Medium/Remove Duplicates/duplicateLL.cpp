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

Node* deleteDuplicates(Node* head) {
        Node* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory for the duplicate node
            } else {
                current = current->next;
            }
        }
        
        return head;
    }

int main(){
    vector<int>ls={1,1,2,3,4,4,5,6};
    Node* head=convertArr2LL(ls);
    head=deleteDuplicates(head);
    print(head);
    return 0;
}