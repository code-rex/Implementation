/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 
*/

/* Approach 
/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Solution (Partition the Array)
 * Take minimum size of two array. Possible number of partitions are from 0 to m in m size array.
 * Try every cut in binary search way. When you cut first array at i then you cut second array at (m + n + 1)/2 - i
 * Now try to find the i where a[i-1] <= b[j] and b[j-1] <= a[i]. So this i is partition around which lies the median.
 *
 * Time complexity is O(log(min(x,y))
 * Space complexity is O(1)
 **/
 
 # Now we can use simple binary search to find out the result.

#    If we have L1 > R1, it means there are too many large numbers on the left half of A1, then we must move C1 to the left 
#    (i.e. move C2 to the right); 
#    If L2 > R1, then there are too many large numbers on the left half of A2, and we must move C2 to the left.
#    Otherwise, this cut is the right one. 
#    After we find the cut, the medium can be computed as (max(L1, L2) + min(R1, R2)) / 2;



      
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m = A.size(), n = B.size();
    
    if(m < n) return findMedianSortedArrays(B, A);
    
    int l = 0, h = 2*n;
    
    while(l <= h)
    {
        int mid = l + (h-l)/2;
        int mid1 = m+n - mid;
        
        double L1 = (mid1 == 0) ? INT_MIN : A[(mid1-1)/2];	
        double L2 = (mid == 0) ? INT_MIN : B[(mid-1)/2];
        double R1 = (mid1 == m*2) ? INT_MAX : A[(mid1)/2];
        double R2 = (mid == n*2) ? INT_MAX : B[(mid)/2];
        
        if (L1 > R2) l = mid + 1;		
        else if (L2 > R1) h = mid - 1;	
        else return (max(L1,L2) + min(R1, R2)) / 2;	
    }
    
}
