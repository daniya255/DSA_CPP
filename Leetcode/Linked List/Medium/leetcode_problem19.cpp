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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case: empty list
    if (head == nullptr)
        return head;
    if (head->next == nullptr)
    {
        if (n == 1)
            return nullptr;
        else
            return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    //Give 'fast' an N-step head start
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    //If fast reached nullptr, it means N is equal to the length of the list,
    // so we need to remove the head node
    if (fast == nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    //Move both fast and slow together until fast reaches the last node
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    //'slow' is now right before the node we want to remove. Bypass it
    ListNode *nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return head;
    }
};