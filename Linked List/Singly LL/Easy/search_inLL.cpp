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

bool searchValue(Node* head, int val) {
    // Pointer to traverse the list
    Node* temp = head;

    // Traverse until end
    while (temp != NULL) {
        // Check if temp node matches key
        if (temp->data == val) {
            // Return true if found
            return true;
        }
        // Move to next node
        temp = temp->next;
        }

    // Return false if not found
    return false;
}

int main(){
   Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Search for value
    if (searchValue(head, 20))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}