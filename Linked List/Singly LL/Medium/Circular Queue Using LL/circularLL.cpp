#include<bits/stdc++.h>
using namespace std;
class CircularQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; 
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Complete the circle back to front
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1; 
        }

        int poppedVal = front->data;

        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; // Update the circular link
            delete temp;
        }

        return poppedVal;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }
};

int main() {
    CircularQueue q;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element (peek): " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element after adding more: " << q.peek() << endl;

    cout << "Clearing the queue:" << endl;
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    cout << "Is queue empty now? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}