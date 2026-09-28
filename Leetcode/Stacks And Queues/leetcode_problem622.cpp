class MyCircularQueue {
     vector<int> data;
    int head;
    int tail;
    int capacity;
    int size;

public:
    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        data[tail] = value;
        tail = (tail + 1) % capacity; // Wrap around if tail reaches the end
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        head = (head + 1) % capacity; // Wrap around if head reaches the end
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        // tail points to the next insertion spot, so the last element is behind it
        int lastIndex = (tail - 1 + capacity) % capacity;
        return data[lastIndex];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
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