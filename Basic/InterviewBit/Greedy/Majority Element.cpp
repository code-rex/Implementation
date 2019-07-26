/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 
*/

//Moore’s Voting Algorithm

int Solution::majorityElement(const vector<int> &A) {
    int count=0;
    int n=A.size();
    int majority=A[0];
    for(int i=0;i<n;i++)
    {
        if(A[i]==majority)
            count++;
        else if(count==0)
        {
            count++;
            majority=A[i];
        }
        else
            count--;
    }
    return majority;
}
