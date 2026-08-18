/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head){

    if(head==nullptr || head->next==nullptr) return head;

    ListNode* prev = NULL;

        // Start from the head of the list
        ListNode* curr = head;

        // Traverse the list
        while (curr != NULL) {
            // Save the next node
            ListNode* front = curr->next;

            // Reverse the current node's pointer
            curr->next = prev;

            // Move prev to current node
            prev = curr;

            // Move to the next node
            curr = front;
        }

        // Return new head (last node becomes first)
        return prev;
    }

ListNode* middleNode(ListNode* head) {
    // If the list is empty or has only
    // one element, return the head asit's the middle.
    if(head==nullptr || head->next==nullptr)   return head;

    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;

}

bool isPalindrome(ListNode* head){

    if(head->next==nullptr) return true;

    ListNode* mid=middleNode(head);
    ListNode* newHead=reverseLL(mid->next);
    ListNode* second=newHead;
    ListNode* first=head;

    while(second!=nullptr){
        if(first->val!=second->val){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
        
    }

    reverseLL(newHead);
    return true;

}

};