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

// Utility function to get the difference in lengths of two linked lists
int getDifference(Node* head1, Node* head2) {
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2;  // If negative, length of list2 > length of list1, else vice-versa
}

Node* intersectionPresent(Node* head1, Node* head2) {
   int diff = getDifference(head1, head2);
    
    if (diff < 0) 
        while (diff++ != 0) head2 = head2->next;
    else 
        while (diff-- != 0) head1 = head1->next;
    
    // Traverse both lists and compare node by node
    while (head1 != NULL) {
        if (head1 == head2) return head1;  // Intersection point found
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;  // Return NULL if no intersection
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

// Time Complexity: O(2 × max(length of list1, length of list2)) + O(abs(length of list1 − length of list2)) + O(min(length of list1, length of list2)), Finding the length of both lists takes O(max) time since it's done simultaneously, then moving one pointer by the difference in lengths, and finally searching for the intersection.
//Space Complexity: O(1), No extra space is used.
