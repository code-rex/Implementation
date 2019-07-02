/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 
*/

// Explanation:https://kartikkukreja.wordpress.com/2016/10/17/detecting-cycle-in-a-linked-list/

ListNode* Solution::detectCycle(ListNode* A) {
    if (A == NULL || A->next == NULL || A->next->next == NULL) 
        return NULL;
    
    ListNode *slow = A, *fast = A;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    
    if (slow != fast) 
        return NULL;
    
    //for loop start one will start from starting and other from the meeting point
    //both at same speed 
    fast = A;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

//for length of loop(pass the slow node from function)
int countNodes(struct Node *n) 
{ 
   int res = 1; 
   struct Node *temp = n; 
   while (temp->next != n) 
   { 
      res++; 
      temp = temp->next; 
   } 
   return res; 
}
