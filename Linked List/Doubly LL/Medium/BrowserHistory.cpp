#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
    
    Node(string url) {
        data = url;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;
    Node* current; 

public:
    BrowserHistory(string homepage) {
        Node* newNode = new Node(homepage);
        head = tail = current = newNode;
    }

    void visit(string url) {
        Node* newNode = new Node(url);
 
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = nullptr; 

            while (temp != nullptr) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }

        current->next = newNode;
        newNode->prev = current;
        
        current = newNode;
        tail = current;
    }

    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->data;
    }

    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->data;
    }

    ~BrowserHistory() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    // Start on "leetcode.com"
    BrowserHistory browser("leetcode.com");
    
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << "Back 1: " << browser.back(1) << endl; 

    cout << "Back 1: " << browser.back(1) << endl; 

    cout << "Forward 1: " << browser.forward(1) << endl; 
    
    browser.visit("linkedin.com");
    
    cout << "Forward 2: " << browser.forward(2) << endl; 
    
    cout << "Back 2: " << browser.back(2) << endl; 
    
    cout << "Back 7: " << browser.back(7) << endl; 

    return 0;
}