/*
Find the longest increasing subsequence of a given sequence / array.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the 
subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.

Example :

Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output : 6
The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]
*/
Time O(n^2)

//Bottom Up
int Solution::lis(const vector<int> &arr) {
    int n=arr.size();
    int lis[n];
    for(int i=0;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    }
    return *max_element(lis,lis+n);
}

//O(nlogn) Approach
int Solution::lis(const vector<int>& nums) {
    vector<int> dp(nums.size());
    int len = 0;
    for (int num:nums) {
        int i = lower_bound(dp.begin(), dp.begin() + len, num) - dp.begin();
        dp[i] = num;
        len = max(len, i + 1);
    }
    return len;
}

//Top Down
#include <iostream>
#include <climits>
using namespace std;

// Function to find length of longest increasing subsequence
int LIS(int arr[], int i, int n, int prev)
{
	// Base case: nothing is remaining
	if (i == n)
		return 0;

	// case 1: exclude the current element and process the
	// remaining elements
	int excl = LIS(arr, i + 1, n, prev);

	// case 2: include the current element if it is greater
	// than previous element in LIS
	int incl = 0;
	if (arr[i] > prev)
		incl = 1 + LIS(arr, i + 1, n, arr[i]);

	// return maximum of above two choices
	return max(incl, excl);
}

// main function
int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Length of LIS is " << LIS(arr, 0, n, INT_MIN);

	return 0;
}


