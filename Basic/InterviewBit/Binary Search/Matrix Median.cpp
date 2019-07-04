/*
Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.
Note: No extra memory is allowed.
*/

/* Check:https://kartikkukreja.wordpress.com/2016/10/11/problem-of-the-day-matrix-median/
1) As the total numbers are odd ,middle one is ans in case of 1Darray.
2) f(x) = count(elements ≤ x) ≥ 1 + N*M/2, where x ∈ [mn, mx]

int findMedian(vector<vector<int> > &A) {
    int mn = A[0][0], mx = A[0][0], n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        if (A[i][0] < mn) mn = A[i][j];
        if (A[i][m-1] > mx) mx = A[i][j];
    }
    
    int desired = (n * m + 1) / 2;
    while (mn < mx) {
        int mid = mn + (mx - mn) / 2;
        int place = 0;
        for (int i = 0; i < n; ++i)
            place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        if (place < desired)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}
