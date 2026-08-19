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

Node* odd_even(Node* head){
    if (head==nullptr || head->next==nullptr)   return head;

    Node* even=head->next;
    Node* odd=head;
    Node* even_head=even;

    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        odd=odd->next;

        even->next=even->next->next;
        even=even->next;
    }

    odd->next=even_head;

    return head;
}

int main(){
   vector<int> arr={1,3,2,5,4};
   Node* head=convertArr2LL(arr);
   head=odd_even(head);
   print(head);
    return 0;
}

//Time Complexity : O(N) - we traverse the LL only once
//Space Complexity : O(1) - no extra spaced used