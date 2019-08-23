/*
https://www.spoj.com/problems/ABCPATH/
You will be given a 2-dimensional grid of letters. Find the length of the longest path of consecutive letters, starting at 'A'. 
Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).

For example, in the following grid, there are several paths from 'A' to 'D', but none from 'A' to 'E':

ABC
One such path is:

path

Input
Each test case will start with a line contains two integers H, W the height and width of the grid respectively 1 <= H, W <= 50. 
Then H lines follow each of W uppercase letters only. Input terminates with H = 0 and W = 0.

Output
For each test case print “Case C: X” without quotes where C is the case number starting with 1 and X is the solution.

Example
Sample Input:
4 3
ABE
CFG
BDH
ABC
0 0

Sample Output:
Case 1: 4
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
void dfs(vector<vector<char>>&a,vector<vector<int>>&dist,int dis,int m,int n,int i,int j)
{
	dist[i][j]=dis+1;
	if(i+1<m && dist[i+1][j] < dist[i][j]+1 && a[i+1][j]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i+1,j);
	if(j+1<n && dist[i][j+1] < dist[i][j]+1 && a[i][j+1]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i,j+1);
	if(i-1>=0 && dist[i-1][j] < dist[i][j]+1 && a[i-1][j]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i-1,j);
	if(j-1>=0 && dist[i][j-1] < dist[i][j]+1 && a[i][j-1]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i,j-1);

	if(i-1>=0 && j-1>=0 && dist[i-1][j-1] < dist[i][j]+1 && a[i-1][j-1]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i-1,j-1);
	if(i+1<m && j-1>=0 && dist[i+1][j-1] < dist[i][j]+1 && a[i+1][j-1]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i+1,j-1);
	if(i+1<m && j+1<n && dist[i+1][j+1] < dist[i][j]+1 && a[i+1][j+1]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i+1,j+1);
	if(i-1>=0 && j+1<n && dist[i-1][j+1] < dist[i][j]+1 && a[i-1][j+1]==(a[i][j]+1))
		dfs(a,dist,dis+1,m,n,i-1,j+1);
}
int32_t main()
{
	int k=1;
	while(1)
	{
		int m,n;
		cin>>m>>n;
		if(m==0 &&n==0)
			break;
		vector<vector<char>>a(m,vector<char>(n,0));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
        vector<vector<int>>dist(m,vector<int>(n,0));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(a[i][j]=='A' && dist[i][j]==0)
					dfs(a,dist,0,m,n,i,j);
		int result=dist[0][0];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				result=max(result,dist[i][j]);
		cout<<"Case "<<k<<": "<<result<<endl;
		k++;
	}
}
