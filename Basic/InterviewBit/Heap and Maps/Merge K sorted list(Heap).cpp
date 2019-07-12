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
