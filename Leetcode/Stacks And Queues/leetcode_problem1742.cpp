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
        
        // 1. Clear all forward history starting from current->next
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = nullptr; // Disconnect the current page from forward nodes
            
            // Delete old forward nodes to free memory
            while (temp != nullptr) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }

        // 2. Link the new node to the current page
        current->next = newNode;
        newNode->prev = current;
        
        // 3. Update current pointer and the tail of the list
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
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */