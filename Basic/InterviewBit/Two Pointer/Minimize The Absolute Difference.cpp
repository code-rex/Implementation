/*
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that 
a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*/
/*
Concept of making 3 points closer
*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i=0,j=0,k=0;
    int minDiff = INT_MAX;
    while(i<A.size() && j<B.size() && k<C.size()){
        int minimum = min(A[i],min(B[j],C[k]));
        int maximum = max(A[i],max(B[j],C[k]));
        int diff = abs(maximum - minimum);
        
        minDiff = min(minDiff,diff);
        
        if(minimum == A[i]) i++;
        else if(minimum == B[j]) j++;
        else k++;
    }
    return minDiff;
}

