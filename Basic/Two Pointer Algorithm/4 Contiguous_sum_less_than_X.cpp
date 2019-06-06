/*
Motivation Problem: Given an array having N integers, find the contiguous subarray having sum as great as possible, but not greater than M. For details on the statement, refer the problem link here

Constraints: Array can have atmost 10^5 elements and each number will be non-negative and can be as big as 10^9.

Solution: As the given array contains positive elements, cumulative sum will indeed be increasing as you go on from left to right in the 
array. If you have already read the binary search tutorial, I am pretty sure you must have found out a way to solve it already.

Solution using binary search:
Store cumulative sum at each index in a separate auxiliary array.
Treat each index as startIndex of the required contiguous subarray, find a corresponding endIndex such that the following equation holds true.
cum[endIndex] - cum[startIndex-1] <= M and cum[endIndex+1] - cum[startIndex-1] > M

Another Approach is sliding window Technique
*/

#include <bits/stdc++.h>
#define lli long long
#define MAX 1000005
 
using namespace std;
 
lli A[MAX];
 
int main()
{
    int n;
	lli sum = 0;	 
    cin >> n;
   
    for ( int i = 0; i < n; i++ ) cin >> A[i];
    
    int l = 0, r = 0;
	lli ans = 0;
 
    while ( l < n ) {
       while ( r < n && sum + A[r] <= M ) {
           sum += A[r];
           r++;
       }
       ans = max(ans, sum);
       sum -= A[l];
       l++;
    }
 
    cout << ans << endl;
    return 0;
}
