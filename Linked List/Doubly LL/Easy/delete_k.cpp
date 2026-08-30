#include<bits/stdc++.h>
using namespace std;
// Node class to represent each node in the linked list
class Node{
    public:
        int data;
        Node* next; // Pointer to the next node
        Node* prev; //Pointer to the prev node

    // Constructor with data and next pointer
    Node(int data, Node* next, Node* prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }

     // Constructor with only data
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }

};

// Function to print the linked list
void print(Node* head){

    //edge case : if linked list is empty
    if (head==NULL) return;
    
    Node*temp= head;

    //traverse till the tail of the linked list 
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

//converts an arr/vector to a linked list and return a pointer to the head
Node* convertArr2DLL(vector<int>arr){

    if (arr.empty()) return nullptr;

    Node* head=new Node(arr[0]);
    Node* prev=head;

    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        prev->next=temp;
        prev=temp;
        
    }

    return head;

}

Node* delK(Node* head, int k){

    if(head==nullptr)   return nullptr;

    if(k==1){
        
        if(head->next!=nullptr){
            //save the reference to the old head
            Node* newNode=head;
            //move the head to next node
            head=head->next;
            //remove the back pointer to the old head
            head->prev=nullptr;
            //isolate the previous head from the LL
            newNode->next=nullptr;
            //delete previous head
            delete newNode;

            return head;
        }
        // If it's the only node in the list
        delete head;
        return nullptr;
    }


    Node* temp=head;
    int count=0;

    while(temp != nullptr && temp->next!=nullptr){
        count++;
        if(count==(k-1)){
            //the target node
            Node* target=temp->next;
            temp->next=target->next;

            // If there is a node after the target, update its prev pointer!
            if(target->next != nullptr){
                target->next->prev = temp;
            }

            target->prev=nullptr;  //the target's back pointer is now pointing to null
            target->next=nullptr;  //the target's next pointer is now pointing to null
            delete(target);    //free target

            break;
        }

        temp=temp->next;
    }

    return head;
}

int main(){
   vector<int>arr={1,2,3,4,5,6};
   Node* head=convertArr2DLL(arr);
   head=delK(head,4);
   print(head);

    return 0;
}