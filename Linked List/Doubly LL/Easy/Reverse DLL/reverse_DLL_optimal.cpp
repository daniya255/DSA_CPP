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
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
        
    }

    return head;

}

// Function to reverse a doubly linked list using a stack (brute force)
Node* reverseDLL(Node* head) {
    // If list is empty or has one node, nothing to reverse
    if (head == nullptr || head->next == nullptr) return head;

    // Pointer to track the current node
    Node* curr = head;

    // Traverse the DLL
    while (curr != nullptr) {
        // Swap next and back pointers of current node
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        // Move to the next node in original order
        head = curr;          
        curr = temp;          
    }

    // Return new head after full reversal
    return head;
}



int main(){
   vector<int>arr={1,2,3,4,5,6};
   Node* head=convertArr2DLL(arr);
   head=reverseDLL(head);
   print(head);

    return 0;
}
 