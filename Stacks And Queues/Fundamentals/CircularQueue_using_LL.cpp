#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class MyCircularQueue {
    Node* rear;
    int size;
    int count;
public:
    MyCircularQueue(int k) {
        size = k;
        count = 0;
        rear = nullptr;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;  // points to itself to maintain the circular link
        } else {
            newNode->next = rear->next; // new node points to front
            rear->next = newNode;       // rear next is now newNode
            rear = newNode;             // Update rear to the new node
        }
        count++;
        return true;
    }
    
    bool deQueue() {
         if (isEmpty()) return false;

        Node* front = rear->next;
        cout << front->data << " removed from the queue." << endl;

        if (rear == front) { // Only one element in the queue
            delete rear;
            rear = nullptr;
        } else {
            rear->next = front->next; 
            delete front;
        }
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return rear->next->data;
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return rear->data;
    }
    
    bool isEmpty() {
        return rear == nullptr;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */