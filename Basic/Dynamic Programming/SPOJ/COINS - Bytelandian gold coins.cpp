/*
https://www.spoj.com/problems/COINS/
Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. 
But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,long long>dp;
long long f(int n)
{
	if(n==0)
		return 0;
	if(dp[n]!=0)
		return dp[n];
	long long aux=f(n/2)+f(n/3)+f(n/4);
	return dp[n]=max(aux,n);
}
int32_t main()
{
    int n;
    while(cin>>n)
        cout<<f(n)<<endl;
}
