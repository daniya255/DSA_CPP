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

// Utility function to insert node at the end of the linked list
void insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
}

// Utility function to check presence of intersection
Node* intersectionPresent(Node* head1, Node* head2) {

    if(head1==nullptr || head2==nullptr) return nullptr;

    Node* temp1=head1;
    Node* temp2=head2;

    // Traverse both lists, when one reaches the end, redirect it to the head of the other list
    while(temp1!=temp2){
        temp1= temp1==nullptr ? head2: temp1->next;
        temp2= temp2==nullptr? head1: temp2->next;
    }

    return temp1;   // If they meet, return the intersection node, otherwise NULL
}

int main(){
   Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    Node* head1 = head;
    head = head->next->next->next;
    
    Node* headSec = NULL;
    insertNode(headSec, 3);
    Node* head2 = headSec;
    headSec->next = head;  // Creating intersection
    
    // Printing the lists
    cout << "List1: "<<endl;
    print(head1);
    cout << "List2: "<<endl;
    print(head2);
    
    // Checking if intersection is present
    Node* answerNode = intersectionPresent(head1, head2);
    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->data << endl;
    return 0;
}

// Time Complexity: O(2 × max(length of list1, length of list2)), Uses the same concept of difference of lengths of two lists.
//Space Complexity: O(1), No extra data structure is used.
