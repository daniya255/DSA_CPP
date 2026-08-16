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

Node* reverseLL(Node* head){

    if(head==nullptr || head->next==nullptr) return head;

    Node* temp=head;

    vector<int> nodes={0};

    while(temp!=nullptr){
        nodes.push_back(temp->data);
        temp=temp->next;
    }

    temp=head;
    int i = nodes.size() - 1;

    while(temp!=nullptr){
        temp->data=nodes[i];
        temp=temp->next;
        i--;
    }

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = reverseLL(head);

    // Printing reversed list
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}

/*
Time Complexity: O(N) ,We traverse the linked list twice once to push all node values into the stack, and once to reassign values. Each traversal takes O(N) time, where N is the number of nodes.
Space Complexity: O(N) , We use an extra vector to store all the node values, which requires O(N) additional space.
*/