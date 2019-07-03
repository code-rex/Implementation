/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    ListNode* start = new ListNode(-1);
    ListNode* cur = start;
    
    while(a!= NULL && b!=NULL)
    {
        if(a->val < b->val)
        {
            cur->next=a;
            cur=cur->next;
            a = a->next;
        }
        else
        {
            cur->next=b;
            cur=cur->next;
            b = b->next;
        }
    }
    while(a!=NULL)
    {
        cur->next=a;
        cur=cur->next;
        a=a->next;
    }
    while(b!=NULL)
    {
        cur->next=b;
        cur=cur->next;
        b=b->next;
    }
    
    cur->next=NULL;
    return start->next;
}
