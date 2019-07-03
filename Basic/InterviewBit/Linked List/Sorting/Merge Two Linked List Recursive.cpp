/*
 Merging Two Linked List from Recursion is not Constant Space . This is because of the extensive use of the call stack.
 Hence For constant space Use iterative method.
 For short and elegant and where memory is not issue .Recursive is preffered.
*/

ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL)
        return B;
    if(B == NULL)
        return A;
    
    if(A->val < B->val)
    {
        A->next = merge(A->next,B);
        return A;
    }
    else
    {
        B->next = merge(A,B->next);
        return B;
    }
} 
