Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* A,ListNode* B)
{
    if(A==NULL) 
        return B;
    if(B==NULL)
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
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int last=A.size()-1;
    while(last!=0)
    {
        int i=0,j=last;
        while(i<j)
        {
            A[i]=merge(A[i],A[j]);
            i++,j--;
            if(i>=j)
                last=j;
        }
    }
    return A[0];
}
