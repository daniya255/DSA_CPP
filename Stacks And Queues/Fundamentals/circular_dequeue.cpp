#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> arr;
    int front, rear, size, capacity;
public:
    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);
        front = 0;
        rear = 0;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return arr[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularDeque myCircularDeque(3);
    cout << myCircularDeque.insertLast(1) << endl; 
    cout << myCircularDeque.insertLast(2) << endl;
    cout << myCircularDeque.insertFront(3) << endl;
    cout << myCircularDeque.insertFront(4) << endl; 
    cout << myCircularDeque.getRear() << endl;    
    cout << myCircularDeque.isFull() << endl;     
    cout << myCircularDeque.deleteLast() << endl; 
    cout << myCircularDeque.insertFront(4) << endl; 
    cout << myCircularDeque.getFront() << endl; 
    return 0;
}