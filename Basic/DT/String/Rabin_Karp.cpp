https://www.spoj.com/submit/NAJPF/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
//Rabin Karp implementation
//s is a pattern and t is a text
vector<int>rabin_karp(string s,string t)
{
	const int p=31;//Must be greater than number of character
	const int m=1e9+9;//Prime number
	
	vector<int>p_pow(max(s.size(),t.size())); //storing powers of p
	p_pow[0]=1;
	for(int i=1;i<(int)p_pow.size();i++)
		p_pow[i]=(p_pow[i-1]*p)%m;

	vector<int>h(t.size()+1,0);//storing hash for every prefix of string t 
	for(int i=0;i<t.size();i++)
		h[i+1]=(h[i]+(t[i]-'a'+1)*p_pow[i])%m;
	int h_s=0;					//calculating hash for pattern
	for(int i=0;i<s.size();i++)
		h_s=(h_s+(s[i]-'a'+1)*p_pow[i])%m;

	vector<int>occurences;
	for(int i=0;s.size()+i-1<t.size();i++) //all window of length s
	{
		int cur_h=(h[i+s.size()]-h[i]+m)%m;
		if(cur_h == h_s*p_pow[i]%m)
			occurences.push_back(i);
	}
	return occurences;
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,t;
		cin>>s>>t;
		vector<int>ans=rabin_karp(t,s);
		if(ans.size()==0)
			cout<<"Not Found"<<endl;
		else{
		cout<<ans.size()<<endl;
		for(auto i:ans)
			cout<<i+1<<" ";
		cout<<endl;
		}
		cout<<endl;
	}
}
