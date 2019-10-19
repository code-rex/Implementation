/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

void reorderList(ListNode* head) {
        if(head!=NULL){
            
       //find the middle one
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //break
        ListNode* head1=slow->next;
        slow->next=NULL;
        ListNode* head2=head;
        
        //reverse the second portion
        ListNode* prev,*curr,*next;
        curr=head1;
        prev=NULL,next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head1=prev;
        //alternate add both
        head = new ListNode(0);
        ListNode* iter=head;
        while(head2 || head1)
        {
            if(head2)   iter->next=head2,head2=head2->next,iter=iter->next;
            if(head1)  iter->next=head1,head1=head1->next,iter=iter->next;
        }
       head=head->next;
        }
    }
