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

void delNode(Node* node){

    //Save the node to be  deleted
    Node* delnode= node->next;

    //Copy the value from the next node
    node->data= node->next->data;

    //Bypass the next node
    node->next= node->next->next;

    //Delete the redundant node to free memory
    delete(node->next);
   
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    Node* nodeToDelete = head->next;
    delNode(nodeToDelete);
    return 0;
}