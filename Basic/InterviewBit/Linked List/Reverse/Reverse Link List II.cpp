/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 
*/

ListNode* reverse(ListNode* A)
{
    //Three pointer technique 
    ListNode* prev=NULL;
    ListNode* curr=A;
    
    while(curr)
    {
        //next pointer links to backward position and other moves forward
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C)
        return A;
    int i=1;
    ListNode *rev=NULL,*rev_prev=NULL,*revend=NULL,*revend_next=NULL;
    ListNode *curr=A;
    //find the Bth position and its previous position and cth position and its next position
    while(curr && i<=C)
    {
        if(i<B)
            rev_prev=curr;
        if(i==B)
            rev=curr;
        if(i==C)
        {
            revend = curr;
            revend_next = curr->next;
        }
        curr = curr->next;
        i++;
    }
    
    revend->next = NULL;
    revend = reverse(rev);
    //if rev_prev is not NULL(revend is now rev)
    if(rev_prev)
        rev_prev->next = revend;
    else
        A = revend;
    //rev is now revend and it points to revend_next    
    rev->next = revend_next; 
    return A; 
}
