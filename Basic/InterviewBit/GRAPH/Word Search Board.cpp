/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 
The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
*/

bool ispresent(vector<string>&A,string B,int n,int m,int i,int j,int k)
{
    if(k==B.length())
        return 1;
    if(i+1<n && A[i+1][j]==B[k])
    {
        if(ispresent(A,B,n,m,i+1,j,k+1))
            return 1;
    }
    if(i-1>=0 && A[i-1][j]==B[k])
    {
        if(ispresent(A,B,n,m,i-1,j,k+1))
            return 1;
    }
    if(j+1<m && A[i][j+1]==B[k])
    {
        if(ispresent(A,B,n,m,i,j+1,k+1))
            return 1;
    }
    if(j-1>=0 && A[i][j-1]==B[k])
    {
        if(ispresent(A,B,n,m,i,j-1,k+1))
            return 1;
    }
    return 0;
}
int Solution::exist(vector<string> &A, string B) {
    int n=A.size();
    int m=A[0].size();
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            if(A[i][j]==B[0])
            {
                if(ispresent(A,B,n,m,i,j,1)==1)
                    return 1;
            }
        }
    }
    return 0;
}
