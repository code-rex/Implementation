/*
Motivation Problem: Given an array having N integers, you need to find out a subsequence of K integers such that these K integers 
have the minimum hustle. Hustle of a sequence is defined as sum of pair-wise absolute differences divided by the number of pairs. 
For details on the statement, refer the problem link here

Constraints: Both N and K are less than or equal to 10^5 and each element has absolute value of around 10^9

Solution:
Anyway, lets see what the problem demands this time. The number of pairs in the function wont be of much significance since we will
always be dividing by fixed number of C(K,2) pairs. So, we can ignore the denominator here and the way function "hustle" is defined 
surely tells us that the numerator of the function will be minimum as much as those K integers will be close to each other. Since, 
hustle function is nothing but merely summation of absolute difference of pairs. Why not just sort the numbers and consider each 
consecutive contiguous subarray of length K for this? That's it. You are done for good !

If you still doubt how we have reduced the problem from subsequence of length K to contiguous substring of length K, 
try to contradict yourself by removing one element from contiguous K elements and taking some other element, you will surely realize, 
what wrong happened their and how much the absolute difference increased overall. Try to prove this way to give yourself complete 
satisfaction about the greedy technique used over here.

Overall complexity of the solution is O(NlogN) + O(N)
To minimize =Hustle
condition = k

Task : Sum of Pairwise Absolute Difference
//1 indexing n=r-l+1;i=l for generalization
for(int i=1;i<=n;i++)
 sum+=a[i]*(i-1)-a[i]*(n-i)
 
 //or by using cumulative sum
 
 #include <bits/stdc++.h>
using namespace std;
 
#define lli long long
#define MAX 1000006
 
lli A[MAX],C[MAX];
 
int main()
{
    int l = 1, r = 2, st,en,n;
    
    lli sum,ans;
 
    cin >> n >> k;
    
    for ( int i = 1; i <= n; i++ ) cin >> A[i];
 
    sort(A+1, A+n+1);
 
    cum[0] = 0;
    for ( int i = 1; i <= n; i++ ) cum[i] = cum[i-1] + A[i];
    
    while ( r <= k ) {
       sum += (A[r]*(r-l) - (cum[r-1] - cum[l-1]));
       r++;
    }
 
    st = 1, en = k, ans = sum;
 
    while ( r <= n ) {
       sum -= (cum[r-1] - cum[l] - A[l]*(r-l-1));
       l++;
       sum += (A[r]*(r-l) - (cum[r-1] - cum[l-1]));
        
       if ( ans > sum ) {
          ans = sum;
          st = l;
          en = r;
       }
       r++;
    }
    return 0;
}
