#include<bits/stdc++.h>
using namespace std;
// Node class to represent each node in the linked list
class Node{
    public:
        int data;
        Node* next; // Pointer to the next node
        Node* prev; //Pointer to the prev node

    // Constructor with data and next pointer
    Node(int data, Node* next, Node* prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }

     // Constructor with only data
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }

};

// Function to print the linked list
void print(Node* head){

    //edge case : if linked list is empty
    if (head==NULL) return;
    
    Node*temp= head;

    //traverse till the tail of the linked list 
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

//converts an arr/vector to a linked list and return a pointer to the head
Node* convertArr2DLL(vector<int>arr){

    if (arr.empty()) return nullptr;

    Node* head=new Node(arr[0]);
    Node* prev=head;

    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        prev->next=temp;
        prev=temp;
        
    }

    return head;

}

// Function to reverse a doubly linked list using a stack (brute force)
Node* reverseDLL(Node* head) {
    // If list is empty or has only one node, return as-is
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Stack to store node data
    stack<int> st;

    // Pointer to traverse the list
    Node* temp = head;

    // Push all node values to stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Reset temp to head for second pass
    temp = head;

    // Replace node values with those from stack
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    // Return head of reversed list
    return head;
}

int main(){
   vector<int>arr={1,2,3,4,5,6};
   Node* head=convertArr2DLL(arr);
   head=reverseDLL(head);
   print(head);

    return 0;
}