/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
         if(head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val?head->next:head;
    }
};