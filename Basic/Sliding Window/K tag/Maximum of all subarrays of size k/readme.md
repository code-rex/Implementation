* Awesome Tutorial : https://people.cs.uct.ac.za/~ksmith/articles/sliding_window_minimum.html
* clean DP Approach : https://stackoverflow.com/a/17249084 
* Always Think about Heap data Structure(Priority queue) only.
* Set vs Priority queue 
  * Priority queue allows acccess to single element(i.e top) .
  * set will sort all data and allows access to all data by linearly iterating over it.
  * for a single element access Priority queue Perfoms better than set.
  
* Queue vs Dequeue

* For a Particular set of Operation (e.q here we want push,pop,access front element) find a suitable(fast) data structure.
  * Binary search tree(multiset in this case) take O(nlogn) because each operation takes logn time.
  * Heap is also same as BST but little faster.
  * Dequeue for all operation take constant time. hence O(n)
