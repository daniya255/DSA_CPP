#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

    Node(int data, Node* next){
        this->data=data;
        this->next=next;
    }

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

};

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

//deletes the  current head of the linked list
Node* delHead(Node* head){

    if (head==nullptr) return nullptr;

    Node*temp=head;
    head= head->next;   //move the head to the next node
    delete temp;
    return head;    //returns the new head
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    print(head);
    head = delHead(head);
    print(head);
    
    return 0;
}