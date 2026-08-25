/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)   return false;

    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    ListNode* slow=head;
    ListNode* fast=head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        // Check if slow and fast pointers meet
        if(slow==fast)  return true;    //loop detected
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;

    }
};