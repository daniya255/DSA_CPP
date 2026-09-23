#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    DoublyLinkedList concatenate(const DoublyLinkedList& other) const {
        
        DoublyLinkedList result;

        Node* temp = this->head;

        while(temp!=nullptr){
            result.append(temp->data);
            temp=temp->next;
        }

        temp = other.head;

        while(temp!=nullptr){
            result.append(temp->data);
            temp=temp->next;
        }

        return result;

    }

};

int main(){
    DoublyLinkedList L ;
    for (int i = 2; i <= 10; i += 2) L.append(i);

    DoublyLinkedList M;
    for (int i = 1; i <= 9; i += 2) M.append(i);

    DoublyLinkedList N = L.concatenate(M);

    cout<<"The concatenated list N is : ";
    N.print();
    cout<<endl;

    
    return 0;
}