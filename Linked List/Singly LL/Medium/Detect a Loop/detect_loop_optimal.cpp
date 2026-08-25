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

bool detectLoop(Node* head){
    if(head==nullptr)   return false;

    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    Node* slow=head;
    Node* fast=head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        // Check if slow and fast pointers meet
        if(slow==fast)  return true;    //loop detected
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
}

int main(){
   // Create sample linked list nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = third;

    // Check if loop exists
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}


//Time Complexity: O(N), we traverse the entire linked list once. The fast pointer either reaches the end of the list or meets the slow pointer in linear time.
//Space Complexity: O(1) , constant amount of extra space is used detect a cycle using Floyd's Cycle Detection Algorithm.
