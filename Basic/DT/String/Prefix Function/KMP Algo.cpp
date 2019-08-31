https://www.spoj.com/problems/NAJPF/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
//Finding prefix function of concatenated string
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) //if mismatch again start matching from value of previous index
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		//t is text s is pattern
		string t,s;
		cin>>t>>s;
		string final=s; //for making s#t
		final+='#';
		final+=t;
		vector<int>ans=prefix_function(final);
		int patlen=s.length();//length of pattern
		vector<int>res;
		for(int i=0;i<ans.size();i++)
		{
			if(ans[i]==patlen)
				res.push_back(i+1-2*patlen);//i+1 for 1 indexing
		}
		if(res.size()==0)
			cout<<"Not Found"<<endl;
		else
		{
			cout<<res.size()<<endl;
			for(auto i:res)
				cout<<i<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}
