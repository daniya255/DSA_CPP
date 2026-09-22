#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert at a specific position / after a given node using reference (&head)
void insertNode(Node* &head, int data, int targetData = -1) {
    Node* newNode = new Node(data);

    // If list is empty
    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    // If targetData is -1, insert at the end
    if (targetData == -1) {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        return;
    }

    // Insert after a given node matching targetData
    Node* curr = head;
    do {
        if (curr->data == targetData) {
            Node* nextNode = curr->next;
            curr->next = newNode;
            newNode->prev = curr;
            newNode->next = nextNode;
            nextNode->prev = newNode;
            return;
        }
        curr = curr->next;
    } while (curr != head);
    
    cout << "Target node not found!\n";
}

void printCDLL(Node* head) {
    if (!head) return;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    
    insertNode(head, 10);          // Insert first (empty list)
    insertNode(head, 20);          // Insert at the end
    insertNode(head, 15, 10);      // Insert after the node with value 10

    cout << "Circular Doubly Linked List: ";
    printCDLL(head);

    return 0;
}