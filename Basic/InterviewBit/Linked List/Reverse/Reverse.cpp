//Simple reverse 

ListNode* Solution::reverseList(ListNode* A) {
    if(A==NULL)
        return NULL;
    if(A->next==NULL)
        return A;
    //Go deep then Link
    ListNode* node=reverseList(A->next);
    A->next->next = A;
    A->next = NULL;
    return node;
}
