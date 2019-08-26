//https://www.spoj.com/problems/ORDERSET/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ordered_set X;
	int t;
	cin>>t;
	while(t--)
	{
    char s;
    cin>>s;
    int n;
    cin>>n;
    //cout<<s<<endl;
    if(s=='I')
    	X.insert(n);
	else if(s=='D'){
		if(X.find(n)!=X.end())
			X.erase(X.find(n));
	}
	else if(s=='K'){
		if(X.size()<n){
			cout<<"invalid"<<endl;
		}
		else
		{
			cout<<*X.find_by_order(n-1)<<endl;
		}
	}
	else if(s=='C')
		cout<<X.order_of_key(n)<<endl;
	}
  return 0;
}
