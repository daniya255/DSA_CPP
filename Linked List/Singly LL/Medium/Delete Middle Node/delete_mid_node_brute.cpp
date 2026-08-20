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

Node* del_mid(Node* head){
    // If the list is empty or has only
    // one element, return nullptr 
    if(head==nullptr || head->next==nullptr)   return nullptr;

    int count=0;
    Node* temp=head;
    
    // Count the number of nodes in the linked list.
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }

    // Calculate the position before the middle node.
    int midnode=count/2;
    temp=head;

    // Traverse to the middle node by moving
    // temp to the middle position.
    while(temp!=nullptr){

        midnode--;
        
        // Check if the middle
        // position is reached.
        if(midnode== 0 ) {
            Node* middle= temp->next;
            temp->next=temp->next->next;
            free(middle);
            break;
        }   
        temp=temp->next;
    }

    return head;

    }

int main(){
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the original linked list
    cout << "Original Linked List: "<<endl;
    print(head);

    // Deleting the middle node
    head = del_mid(head);

    // Displaying the updated linked list
    cout << "Updated Linked List: "<<endl;
    print(head);

    return 0;
}

// Time Complexity: O(N + N/2), we traverse the entire linked list once to count the number of nodes and then traverse again to delete the middle node.
// Space Complexity: O(1) , we have fixed number of pointers and variables to delete the Kth node.

