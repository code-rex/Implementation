/*
Motivation Problem: Given two sorted arrays A and B, each having length N and M respectively. Form a new sorted merged array having values of both the arrays in sorted format.

Constraints: Array A and B contains about 105 integers, each having value around 109.
*/

#define MAX 100005
 
lli C[2*MAX];
 
void merge(lli A[], lli B[])
{
    int l1 = 0, l2 = 0, cnt = 0;
    while ( l1 < n || l2 < m ) {
       if ( l1 < n && l2 < m ) {
          if ( A[l1] < B[l2] ) {
              C[cnt++] = A[l1]; 
              l1++;
          }
          else if ( A[l1] > B[l2] ) {
              C[cnt++] = B[l2];
              l2++;
          }
       }
       else if ( l1 < n ) {
          C[cnt++] = A[l1];
          l1++;
       }
       else if ( l2 < m ) {
          C[cnt++] = B[l2];
          l2++; 
       }
    }
    return;
}
