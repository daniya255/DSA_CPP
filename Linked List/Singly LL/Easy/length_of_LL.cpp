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

//returns the length of the linked list
int lengthLL(Node* head){

    if(head==nullptr) return 0;

    int count=0;
    Node* temp= head;

    while(temp!=nullptr){
        temp= temp->next;
        count++;
    }

    return count;

}

int main(){
    vector<int> arr= {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    cout<<"The length of the linked list is : "<<lengthLL(head)<<endl;
    return 0;
}