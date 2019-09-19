//Given a string . finding all subset whose all number are prime.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
const int N=pow(10,6)+1;
bool prime[N];
void sieve()
{
	for(int i=0;i<N;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	prime[2]=1;
	for(int i=4;i<N;i+=2)
		prime[i]=false;
	for(int i=3;i*i<N;i+=2)
	{
		if(prime[i])
		{
			for(int j=i*2;j<N;j+=i)
				prime[j]=false;
		}
	}
}
void countpart(int start,string &s,vector<int>&aux,vector<vector<int>>&ans)
{
	if(start==s.size())
	{
		ans.push_back(aux);
		return;
	}
	for(int length=1;length<=s.length()-start;length++)
	{
		string k=s.substr(start,length);
		int n=stoi(k);
		if(prime[n]==true)
		{
			aux.push_back(n);
			countpart(start+length,s,aux,ans);
			aux.pop_back();
		}
	}
}
int32_t main()
{
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		vector<int>aux;
		vector<vector<int>>ans;
		countpart(0,s,aux,ans);
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<ans[i].size();j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
}
