/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //Divide into two list then match
        if(head==NULL)
            return true;
        //1.find middle point
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *head1=slow->next;
        slow->next=NULL;
        //2.Reverse the second part
        ListNode* prev=NULL,*next=NULL,*curr=head1;
        while(curr)
        {
            ListNode* next=curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        //3.prev is starting of second portion
        //Start Macthing
        ListNode* l1=head,*l2=prev;
        while(l1 && l2)
        {
            if(l1->val!=l2->val)
                return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
        
    }
};
