/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
         ListNode beforeHead(0);
    ListNode afterHead(0);
    ListNode* before = &beforeHead;
    ListNode* after = &afterHead;

    for (; head; head = head->next)
      if (head->val < x) {
        before->next = head;
        before = head;
      } else {
        after->next = head;
        after = head;
      }
    after->next = nullptr;
    before->next = afterHead.next;
    return beforeHead.next;
    };
};

