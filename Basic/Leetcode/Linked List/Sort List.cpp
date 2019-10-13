ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)     return l2;
        if(l2==NULL)    return l1;
        
        if(l1->val<l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* sortList(ListNode* head) {
        //1.Divide the linked list(from Middle) then merge
        if(!head || !head->next)  return head;
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next)
            slow=slow->next,fast=fast->next->next;
        
        ListNode* head1=slow->next;
        slow->next=NULL;
        return mergeTwoLists(sortList(head),sortList(head1));
    }
