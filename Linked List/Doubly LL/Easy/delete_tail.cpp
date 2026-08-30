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

Node* delTail(Node* head){
    if(head==nullptr || head->next==nullptr)   return nullptr;

    Node* temp=head;
    while(temp->next->next!=nullptr){
       temp=temp->next;
    }

    Node* target = temp->next; // the tail
    temp->next = nullptr;
    target->prev = nullptr;
    delete target;

    return head;
    
}

int main(){
   vector<int>arr={1,2,3,4,5,6};
   Node* head=convertArr2DLL(arr);
   head=delTail(head);
   print(head);

    return 0;
}


// Time Complexity: O(n), where n is the number of nodes in the doubly linked list. This is because we traverse the list to find the tail node before inserting the new node.
// Space Complexity: O(1), as we are only using a constant amount of extra space for the new node, regardless of the size of the list.