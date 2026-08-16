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
    ListNode* reverseList(ListNode* head) {
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
};