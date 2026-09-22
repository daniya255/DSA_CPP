#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* rear; 

public:
    CircularQueue() {
        rear = nullptr;
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    //Insert an element at the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;  // points to itself to maintain the circular link
        } else {
            newNode->next = rear->next; // new node points to front
            rear->next = newNode;       // rear next is now newNode
            rear = newNode;             // Update rear to the new node
        }
        cout << value << " inserted into the queue." << endl;
    }

    //Remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! The queue is empty." << endl;
            return;
        }

        Node* front = rear->next;
        cout << front->data << " removed from the queue." << endl;

        if (rear == front) { // Only one element in the queue
            delete rear;
            rear = nullptr;
        } else {
            rear->next = front->next; 
            delete front;
        }
    }

    // Get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->next->data; 
    }

    // Display the elements of the circular queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = rear->next;
        cout << "Circular Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }

    ~CircularQueue() {
        if (!isEmpty()) {
            Node* current = rear->next;
            rear->next = nullptr; // Break the circle to prevent infinite loop
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}