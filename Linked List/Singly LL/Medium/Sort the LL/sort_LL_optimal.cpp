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

Node* mergeCombine(Node* list1,Node* list2){

    // A dummy node to act as the start of our merged list
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;

    // Compare nodes from both lists and attach the smaller one
    while(list1 != nullptr && list2 != nullptr) {
        if(list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If any nodes are left over in either list, attach them
    if(list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Return the sorted list starting after the dummy node
    return dummyNode->next;
}

Node* sortLL(Node* head){
    if(head==nullptr || head->next==nullptr) return head;

    Node* slow=head;
    Node* fast=head->next;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* newHead=slow->next;
    slow->next=nullptr;

    Node* left=sortLL(head);
    Node* right=sortLL(newHead);
    return mergeCombine(left,right);

}

int main(){
   // Create linked list: 3 -> 2 -> 5 -> 4 -> 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    // Print original list
    cout << "Original Linked List: "<<endl;
    print(head);

    // Sort the linked list
    head = sortLL(head);

    // Print sorted list
    cout << "Sorted Linked List: "<<endl;
    print(head);
    return 0;
}


// Time Complexity: O(N*LogN), we recursively divide the linked list into two halves and then merge two sorted halves.
// Space Complexity: O(1) , constant additional space is required to sort the entire linked list.
