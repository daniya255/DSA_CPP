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

Node* detectCycle(Node* head){

    if(head==nullptr)   return head;

    unordered_map<Node*,int>mpp;
    Node* temp=head;

    while(temp!=nullptr){

        if(mpp.find(temp)!=mpp.end())   return temp;

        mpp[temp]=1;
        temp=temp->next;
    }

    return nullptr;
}
int main(){
   // Create sample linked list nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = second;

    Node* result=detectCycle(head);
    // Check if loop exists
    if (result!=nullptr) {
        int index = 0;
        Node* curr = head;
        
        // Walk from head until we hit the result node, counting steps
        while (curr != result) {
            curr = curr->next;
            index++;
        }
        cout << "Loop detected in the linked list at index : "<<index<< endl;
    } 
    else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

  
    return 0;
}

// Time Complexity: O(N*LogN), we traverse the entire linked list once and store and retrieve nodes from the hash map. Map operations have a worst time space complexiy of O(LogN).
// Space Complexity: O(N) , additional amount of extra space is used to store nodes in a hash map.