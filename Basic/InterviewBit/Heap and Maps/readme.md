In c++ Priority_queue is max heap(by default).(node is maximum then both of its child node).

For Max Heap : priority_queue<int>pq;
For Min heap : priority_queue<int,vector<int>,greater<int>()>pq;

We can also use any comparator function in place of greater<int>
  struct comp
  {
    bool operator()(ListNode* A,ListNode* B){
      return A->val > B->val;
    }
   };
   
with Comparater : priority_queue<int,vector<int>,comp>pq;
  
Functions: push,pop,top,empty,erase 
