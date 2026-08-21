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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(head1==nullptr || head2==nullptr) return nullptr;

    ListNode* temp1=head1;
    ListNode* temp2=head2;

    // Traverse both lists, when one reaches the end, redirect it to the head of the other list
    while(temp1!=temp2){
        temp1= temp1==nullptr ? head2: temp1->next;
        temp2= temp2==nullptr? head1: temp2->next;
    }

    return temp1;   // If they meet, return the intersection node, otherwise NULL
    }
};