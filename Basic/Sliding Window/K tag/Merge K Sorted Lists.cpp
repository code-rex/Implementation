/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/

//Approach 1 - Priority queue Approach
struct CompareNode 
{
    bool operator()(ListNode* const & p1, ListNode* const & p2) {
    // return "true" if "p1" is ordered before "p2", for example:
        return p1->val > p2->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &lists) {
            ListNode* dummy = new ListNode(0);
            ListNode* tail = dummy;

            priority_queue<ListNode*,vector<ListNode*>,CompareNode> queue;

            for (int i = 0; i < lists.size(); i++) 
                    queue.push(lists[i]);

            while (!queue.empty()) {
                    tail->next = queue.top();
                    queue.pop();
                    tail = tail->next;

                    if (tail->next)
                            queue.push(tail->next);
            }

            return dummy->next;
    
}

//Approach 2
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
