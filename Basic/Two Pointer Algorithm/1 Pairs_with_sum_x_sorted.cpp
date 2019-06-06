/*
Motivation Problem: Given a sorted array A, having N integers. You need to find any pair(i,j) having sum as given number X.

Constraints: Array  A  contains about 105 integers with each having values around 109.
*/

#define lli long long
bool f(lli sum) {
    int l = 0, r = n - 1; //two pointers
    while ( l < r ) {
       if ( A[l] + A[r] == sum ) return 1;
       else if ( A[l] + A[r] > sum ) r--;
       else l++;
    }
    return 0;
}
