/*
Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.
*/

void dfs(vector<string>&A,int n,int m,int i,int j)
{
    A[i][j]='O';
    if(i-1>=0 && A[i-1][j]=='X')
        dfs(A,n,m,i-1,j);
    if(j-1>=0 && A[i][j-1]=='X')
        dfs(A,n,m,i,j-1);
    if(i+1<n && A[i+1][j]=='X')
        dfs(A,n,m,i+1,j);
    if(j+1<m && A[i][j+1]=='X')
        dfs(A,n,m,i,j+1);
}
int Solution::black(vector<string> &A) {
    int n=A.size();
    int m=A[0].size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='X')
            {
                dfs(A,n,m,i,j);
                ans++;
            }
        }
    }
    return ans;
}


