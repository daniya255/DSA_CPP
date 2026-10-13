#include<bits/stdc++.h>
using namespace std;
class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = new Node(0); // Dummy head node
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        
        Node* curr = head->next;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        
        Node* prev = head;
        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        Node* prev = head;
        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
    }
};
int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(5);
    obj->addAtTail(6);
    obj->addAtIndex(3,4);
    int param_1 = obj->get(2);
    obj->deleteAtIndex(1);

    return 0;
}

