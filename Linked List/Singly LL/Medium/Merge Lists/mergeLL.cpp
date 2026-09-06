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

Node* mergeTwoLists(Node* list1, Node* list2) {
        Node dummy(0);
        Node* current = &dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->data <= list2->data) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        current->next = (list1 != nullptr) ? list1 : list2;
        
        return dummy.next;
    }

int main(){
    vector<int>l1={1,3,5};
    vector<int>l2={2,4,6};
    Node* h1=convertArr2LL(l1);
    Node* h2=convertArr2LL(l2);
    Node* mergedHead=mergeTwoLists(h1,h2);
    print(mergedHead);
    return 0;
}