/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* last = head;
        ListNode* current = head->next;
        
        while(current != NULL){
            if(current->val == last->val){
                //remove cur
                last->next = current->next;
            }else{
                //update last only if cur isn't duplicate
                last = current;
            }
            current = current->next;
        }
        
        return head;
    }
};