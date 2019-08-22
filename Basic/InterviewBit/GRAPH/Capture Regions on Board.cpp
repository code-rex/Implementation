/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

void dfs(vector<vector<char>>&A,int i,int j)
{
    if(i>=A.size() || j>=A[0].size() || i<0 || j<0)
        return ;
    if(A[i][j]!='-')
        return ;
    A[i][j]='O';
    dfs(A,i-1,j);
    dfs(A,i+1,j);
    dfs(A,i,j-1);
    dfs(A,i,j+1);
}
void Solution::solve(vector<vector<char> > &A) {
    int n=A.size();
    int m=A[0].size();
    /*
    Approach 1)changing all 'O' to '-'
    2)changing all '-' to 'O' of all edge
    */
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='O')
                A[i][j]='-';
        }
    }
    //------Checking edges------------
    //first and last row
    for(int j=0;j<m;j++)
    {
        if(A[0][j]=='-')
            dfs(A,0,j);
        if(A[n-1][j]=='-')
            dfs(A,n-1,j);
    }
    //first and last column
    for(int i=0;i<n;i++)
    {
        if(A[i][0]=='-')
            dfs(A,i,0);
        if(A[i][m-1]=='-')
            dfs(A,i,m-1);
    }
    
    //changing the reamining - to X
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='-')
                A[i][j]='X';
        }
    }
}
