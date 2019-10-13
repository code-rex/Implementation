ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA,*b=headB;
        while(a!=b)
        {
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    }
