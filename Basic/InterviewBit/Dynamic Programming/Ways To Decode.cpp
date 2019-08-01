/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example :

Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

//RECURSIVE
/*
So, when looking at the start of the string, we can either form a one digit code, 
and then look at the ways of forming the rest of the string of length L - 1, or we can 
form 2 digit code if its valid and add up the ways of decoding rest of the string of 
length L - 2.
*/

int ways(const string& A, int s)
{
    if(s == A.size())
        return 1;
    if(A[s] == '0')
        return 0;
    if(A[s] > '2')
        return ways(A,s+1);
    if(s+1 >= A.size())
        return ways(A,s+1);
    if(A[s] == '1' 
            || (A[s] == '2' && A[s+1] < '7'))
        return ways(A,s+1) +  ways(A,s+2);
    else
        return ways(A,s+1);
}
 
 
int Solution::numDecodings(string A) {
    return ways(A,0);
}

//Iterative
int Solution::numDecodings(string A) {
 int n=A.length();
 
 int count[n+1];
 if(A[0] == '0'){
     return 0;
 }
 count[0]=1;
 count[1] = 1;
 
 for(int i=2;i<=n;i++){
     count[i]=0;
     if(A[i-1]>'0')
         count[i] = count[i-1];
     if(A[i-2]=='1' || (A[i-2]=='2' && A[i-1]<'7'))
         count[i]+=count[i-2];
 }
 
 return count[n];
}
