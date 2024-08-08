/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode dummy(0, head);
    ListNode* prev = &dummy;

    while (head) {
      while (head->next && head->val == head->next->val)
        head = head->next;
      if (prev->next == head)
        prev = prev->next;
      else
        prev->next = head->next;
      head = head->next;
    }

    return dummy.next;
    }
};