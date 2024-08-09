class Solution {
public:
int getCount(ListNode* head)
{
if (head == NULL) {
return 0;
}
else {
return 1 + getCount(head->next);
}
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=getCount(headA);
    int l2=getCount(headB);
    if(l1<l2){
        swap(headA,headB);
        swap(l1,l2);
    }
    while(l1>l2){
        headA=headA->next;
        l1--;
    }
    while(headA!=headB){
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
    }
};