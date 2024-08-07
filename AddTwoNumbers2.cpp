/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* l = dummy;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            }
            else {
                carry = 0;
            }

            l->next = new ListNode(sum);
            l = l->next;
        }
        
        if (carry) {
            l->next = new ListNode(carry);
        }
        
        return dummy->next;

    }
};