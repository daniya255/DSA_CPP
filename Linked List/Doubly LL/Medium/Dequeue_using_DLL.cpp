#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << value << " inserted at front." << endl;
    }

    void insertRear(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << value << " inserted at rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << temp->data << " deleted from front." << endl;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // List became empty
        }
        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Queue is empty." << endl;
            return;
        }
        Node* temp = rear;
        cout << temp->data << " deleted from rear." << endl;
        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr; // List became empty
        }
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Deque elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};

int main(){
    Deque dequeue;
    dequeue.insertFront(4);
    dequeue.insertRear(5);
    dequeue.insertFront(6);
    cout<<dequeue.isEmpty()<<endl;
    dequeue.deleteFront();
    dequeue.display();
    return 0;
}