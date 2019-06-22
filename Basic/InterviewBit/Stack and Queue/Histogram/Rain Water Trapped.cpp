/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Rain water trapped: Example 1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
*/

/*
Logic:If the water is stored at some position i means there are building larger than ith building both side;
->And at every index i the stored water is min(left,right)-A[i](the height of current building)

1st Solution :Space Complexity and Time complexity O(n)
Make two array left and right. left[i] will contain maximum element encounter till i along with i form left(runs from 1-n),
same for right[i] from right position
*/
Optimal Solution space O(1) Time O(n)

int Solution::trap(const vector<int> &A) {
    int n=A.size();
    int lo=0,hi=n-1;
    int left_max=0,right_max=0;
    int result=0;
    while(lo<=hi)
    {
        if(A[lo]<A[hi])
        {
            if(A[lo]>left_max)
                left_max=A[lo];
            else
                result+=left_max-A[lo];
            lo++;
        }
        else
        {
            if(A[hi]>right_max)
                right_max=A[hi];
            else
                result+=right_max-A[hi];
            hi--;
        }
    }
    return result;
}


