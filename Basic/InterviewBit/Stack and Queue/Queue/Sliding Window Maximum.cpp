/*
A long array A[] is given to you. There is a sliding window of size w which is moving from the very left of the array to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by one position. You have to find the maximum for each window. The following example will give you more clarity.

Example :

The array is [1 3 -1 -3 5 3 6 7], and w is 3.

Window position	Max
 	 
[1 3 -1] -3 5 3 6 7	3
1 [3 -1 -3] 5 3 6 7	3
1 3 [-1 -3 5] 3 6 7	5
1 3 -1 [-3 5 3] 6 7	5
1 3 -1 -3 [5 3 6] 7	6
1 3 -1 -3 5 [3 6 7]	7
Input: A long array A[], and a window width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
Requirement: Find a good optimal way to get B[i]

 Note: If w > length of the array, return 1 element with the max of the array. 
*/
/*
Logic: The key is to maintain the max element at the top of the queue(for a window ) and discarding the useless elements and 
we also need to discard the elements that are out of index of current window.

useless elements = If Current element is greater than the last element of queue than the last element of queue is useless . 

Note : We are storing the index in queue not the element itself. It will be more clear from the code itself. 
1. If Current element is greater than the last element of queue than the last element of queue is useless .
We need to delete that last element. (and keep deleting until the last element of queue is smaller than current element).
2. If if current_index - k >= q.front() that means we are going out of window so we need to delete the element from front of queue. 
*/
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
  
    vector<int> v;
    deque<int> dq;
        
    for(auto i=0; i<A.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-B)
            dq.pop_front();
        
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
            
        dq.push_back(i);
        
        if(i >= B-1) v.push_back(A[dq.front()]);
    }
    
    return v;
}



