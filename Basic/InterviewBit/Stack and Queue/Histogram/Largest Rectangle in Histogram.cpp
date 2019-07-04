/*
Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10;
*/

/* Approach
Nice Explanation : http://srinu634.blogspot.com/2014/05/maximum-area-in-histogram.html
References : https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

1) Assume that the maximum answer is by the smallest height bar (As it is smallest it will take consider all bar) 
    hence ans is n*A[smallest].
2) So, if the rectangle at i is considered to be the minimum height rectangle, what can be the maximum area with i as the 
    minimum height rectangle? We can include all those rectangle to the left and to the right  of i such that their height is 
    atleast the height of rectangle i. 
    area[i] = h[i] * ( l + l + r );
3) Our goal is to calculate l,r for each index i , if we can do it in O(1) , We got an O(n) Solution.
*/
/*
Rough idea of the Algorithm:
1) Push the first bar
2)  if the ith bar has height  > bar on the top of the stack , push ith bar to stack
3) if ith bar is less than top pop top element from stack and calculate its area
4) while( s.top().height < height[i] || s.empty()!=TRUE )
       pop the top element and calculate its area
5) if ( i == n ) 
         keep on popping and calculating the area 
*/

int Solution::largestRectangleArea(vector<int> &A) {
    int n=A.size();
    if(n==1)
        return A[0];
    stack<int>s;
    int area;
    int maxarea=INT_MIN;
    int i=0;
    while(i<n)
    {
        if(s.empty() || A[i]>=A[s.top()])
            s.push(i++);
        else
        {
            int top=s.top();
            s.pop();
            area = A[top]*(s.empty() ? i : i-s.top()-1);
            maxarea = max(area,maxarea);
        }
    }
    
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        area = A[top]*(s.empty() ? i : i-s.top()-1);
        maxarea = max(area,maxarea);
    }
    return maxarea;
}
