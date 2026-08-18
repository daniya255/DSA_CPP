#include<bits/stdc++.h>
using namespace std;
// Node class to represent each node in the linked list
class Node{
    public:
        int data;
        Node* next; // Pointer to the next node

    // Constructor with data and next pointer
    Node(int data, Node* next){
        this->data=data;
        this->next=next;
    }

     // Constructor with only data
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

};

// Function to print the linked list
void print(Node* head){

    //edge case : if linked list is empty
    if (head==NULL) return;
    
    Node*temp= head;

    //traverse till the tail of the linked list to connect nodes together 
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

//converts an arr/vector to a linked list and return a pointer to the head
Node* convertArr2LL(vector<int>arr){

    if (arr.empty()) return nullptr;

    Node* head=new Node(arr[0]);
    Node* temp=head;

    for(int i=1;i<arr.size();i++){
        temp->next= new Node(arr[i]);
        temp = temp->next;
    }

    return head;

}

Node* reverse_LL(Node* head){

    if(head==nullptr || head->next==nullptr) return head;

    Node* newNode=reverse_LL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newNode;

}

int main(){
   Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = reverse_LL(head);

    // Printing reversed list
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}

/*
Time Complexity: O(n),Each node is visited exactly once during the recursive call, and we do constant-time work for each node (like flipping pointers).
Space Complexity: O(n),The recursion stack goes up to n levels deep (one for each node), which uses extra space on the call stack.

*/