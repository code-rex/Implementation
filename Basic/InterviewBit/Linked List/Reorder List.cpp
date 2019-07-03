/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/*
1) Find the middle point using tortoise and hare method.
2) Split the linked list into two halves using found middle point in step 1.
3) Reverse the second half.
4) Do alternate merge of first and second halves. 
*/

void reverse(ListNode **a)
{
    ListNode *prev=NULL,*curr=*a,*next;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *a = prev;
}
ListNode* Solution::reorderList(ListNode* a) {
    
    //1.Finding the middle point 
    ListNode *slow=a;
    ListNode *fast=a;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //Making two seperate list
    ListNode *head = slow->next;
    slow->next = NULL;
    fast = a;
    
    //Reversing after middle node
    reverse(&head);
    
    //alternating assigning nodes using dummy node
    ListNode* start = new ListNode(0);
    ListNode* curr = start;
    
    while(head || fast)
    {
        if(fast)
        {
            curr->next = fast;
            fast = fast->next;
            curr = curr->next;
        }
        if(head)
        {
            curr->next = head;
            head = head->next;
            curr = curr->next;
        }
    }
    return start->next;
       
}
