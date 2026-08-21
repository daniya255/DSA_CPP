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

// Function to sort the linked list
Node* sortLL(Node* head) {
        // Vector to store node values
        vector<int> arr;

        // Pointer to traverse the list
        Node* temp = head;

        // Traverse and push values into vector
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Sort the vector
        sort(arr.begin(), arr.end());

        // Reassign sorted values to list nodes
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->data = arr[i];
            temp = temp->next;
        }

        // Return head of sorted list
        return head;
}


int main(){
   // Create linked list: 3 -> 2 -> 5 -> 4 -> 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    // Print original list
    cout << "Original Linked List: ";
    print(head);

    // Sort the linked list
    head = sortLL(head);

    // Print sorted list
    cout << "Sorted Linked List: ";
    print(head);
    return 0;
}

// Time Complexity: O(2*N + N*LogN), we traverse the linked list, store its elements in an array, sort it, and then copy the sorted values back into the original list.
// Space Complexity: O(N) , additional space required to store all the elements of linked list in an array.