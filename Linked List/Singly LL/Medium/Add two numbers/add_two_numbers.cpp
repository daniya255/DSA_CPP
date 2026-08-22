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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummyHead = new Node(0);
    Node* current = dummyHead;
    int carry = 0;

    // Loop while there are digits left in l1, l2, or if we still have a carry left over
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;          // Calculate new carry (e.g., 15 / 10 = 1)
        current->next = new Node(sum % 10); // Store the last digit (e.g., 15 % 10 = 5)
        current = current->next;   // Move forward
    }

    Node* result = dummyHead->next;
    delete dummyHead; // Clean up memory
    return result;
}

int main(){
   vector<int>l1={6,7,2,1};
   vector<int>l2={2,9,6,4,8,1};
   Node* head1=convertArr2LL(l1);
   Node* head2=convertArr2LL(l2);
   Node* result=addTwoNumbers(head1,head2);
   print(result);
    return 0;
}

// Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.