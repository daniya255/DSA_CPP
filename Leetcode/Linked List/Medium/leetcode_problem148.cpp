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
    ListNode* mergeCombine(ListNode* list1,ListNode* list2){

    // A dummy node to act as the start of our merged list
    ListNode* dummyNode = new ListNode(-1);
    ListNode* current = dummyNode;

    // Compare nodes from both lists and attach the smaller one
    while(list1 != nullptr && list2 != nullptr) {
        if(list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If any nodes are left over in either list, attach them
    if(list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Return the sorted list starting after the dummy node
    return dummyNode->next;
}

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead=slow->next;
        slow->next=nullptr;

        ListNode* left=sortList(head);
        ListNode* right=sortList(newHead);
        return mergeCombine(left,right);
    }
};