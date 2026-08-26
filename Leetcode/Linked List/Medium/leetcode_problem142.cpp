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
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr)
            return head;

        // Initialize two pointers, slow and fast,
        // to the head of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 2: Traverse the linked list with
        // the slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                slow = head;

                // if they met , reset one of the pointers to the head
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // return the node where the pointers met again (the starting
                // point of loop)
                return slow;
            }
        }

        // return null, if linked list is traversed completely
        return nullptr;
    }
};