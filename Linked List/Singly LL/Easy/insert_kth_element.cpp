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

Node* insertK(Node* head,int k,int val){

    if(head==nullptr){
        if(k==1){
            Node* temp= new Node(val,head);
            return temp;
        }

        return nullptr;
    }

    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }

    Node*temp=head;
    int count=0;

    while(temp!=nullptr){
        count++;
        if(count==(k-1)){
            Node* newNode= new Node(val,temp->next);
            temp->next=newNode;
            break;
    
        }
        temp=temp->next;
    }
     return head;
}

int main(){
   Node* head=new Node(20);
   head->next =new Node(30);
   head->next->next=new Node(40);
   head->next->next->next=new Node(60);
   head=insertK(head,2,10);
   print(head);

    return 0;
}