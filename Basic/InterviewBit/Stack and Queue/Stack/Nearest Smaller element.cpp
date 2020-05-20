/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10, 8]
Return : [-1, 4, -1, 2, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]
*/

Time complexity : O(n)
Space : O(n) using stack
/*
Discussion :
1) Create a new empty stack st

2) Iterate over array `A`,
   where `i` goes from `0` to `size(A) - 1`.
    a) We are looking for value just smaller than `A[i]`. So keep popping from `st` till elements in `st.top() >= A[i]` or 
       st becomes empty.
    b) If `st` is non empty, then the top element is our previous element. Else the previous element does not exist. 
    c) push `A[i]` onto st
 Notice that the element in stack is sorted .
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int>ans;
    int n=A.size();
    stack<int>s;

    for(int i=0;i<n;i++)
    {
        while(!s.empty() && s.top()>=A[i])
            s.pop();
        if(s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());
        s.push(A[i]);
    }
    return ans;
}
