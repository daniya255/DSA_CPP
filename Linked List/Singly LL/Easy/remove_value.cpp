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

Node* removeEl(Node* head,int val){

    if(head==nullptr) return head;

    if(head->data==val){
        head=head->next;
        return head;
    }

    Node* temp=head;
    Node* prev=NULL;

    while(temp!=nullptr){
        if(temp->data == val){
           prev->next=prev->next->next;
           free(temp);
           break;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
    
}
int main(){
   Node* head= new Node(20);
   head->next= new Node(30);
   head->next->next= new Node(40);
   Node* newHead= removeEl(head,40);
   print(newHead);
    return 0;
}