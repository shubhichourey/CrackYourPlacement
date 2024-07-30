/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode * dummy = new ListNode(0);
           dummy->next = head;
           ListNode* curr = dummy , *nex = dummy , *pre = dummy;
           int cnt = 0;
           while(curr->next) {
               curr = curr->next;
               cnt++;
           } 
           while(cnt >= k) {
               curr = pre->next;
               nex = curr->next;
               for(int i=1;i<k;i++) {
                   curr->next = nex->next;
                   nex->next = pre->next;
                   pre->next = nex;
                   nex = curr->next;
               }
               pre = curr;
               cnt-=k;
           }
        return dummy->next;
    }
};