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
