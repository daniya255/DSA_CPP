#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

     // Constructor with data and next pointer
    Node(int data, Node* next){
        this->data=data;
        this->next=next;
    }

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

};

// Function to print the linked list
void print(Node* head){
    if (head==NULL) return;
    
    Node*temp= head;

    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

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


Node* insertHead(Node* head,int val){

    // Create a new node whose next points to current head
    Node * newHead =  new Node (val, head);

    // Return the new node as the head
    return newHead;
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    Node * newHead= insertHead(head,7);
    print(newHead);
      
    return 0;
}