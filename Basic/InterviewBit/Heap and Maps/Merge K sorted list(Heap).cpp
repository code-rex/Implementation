/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comp{
  bool operator()(ListNode* A,ListNode* B){
    return A->val > B->val;
  }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // priority_queue 'pq' implemeted as min heap with the 
    // help of 'compare' function 
    priority_queue<ListNode*,vector<ListNode*>,comp>pq;
    ListNode* head=NULL,*last;
    //Pushing top node of every list
    for(int i=0;i<A.size();i++)
        pq.push(A[i]);
    while(!pq.empty())
    {
        ListNode* top=pq.top();
        pq.pop();
        
        if(top->next!=NULL)
            pq.push(top->next);
            
        if(head == NULL)
        {
            head = top;
            last = top;
        }
        else
        {
            last->next = top;
            last = top;
        }
    }
    return head;
}


//OR
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
