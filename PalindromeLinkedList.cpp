/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.*/

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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *s = head, *f = head, *c = head, *p = nullptr;
        while(f && f->next){
            c = s;
            s = s->next;
            f = f->next->next;
            c->next = p;
            p = c;
        }
        if(f) s = s->next;
        while(p && p->val == s->val){
            p = p->next;
            s = s->next;
        }
        return !p;
        
    }
};