#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int a[x],b[y];
		for(int i=0;i<x;i++)
			cin>>a[i];
		for(int i=0;i<y;i++)
			cin>>b[i];
		int ans[x+y];
		int l=0,r=0;
		for(int i=0;i<x+y;i++)
		{
			if(l<x && r<y)
			{
			if(a[l]>=b[r])
				ans[i]=b[r++];
			else if(a[l]<=b[r])
				ans[i]=a[l++];
			}
			//if b comes to an end
			else if(r<y )
				ans[i]=b[r++];
			else if(l<x)
				ans[i]=a[l++];

		}
		for(int i=0;i<x+y;i++)
			cout<<ans[i]<<" ";
		cout<<endl;

	}
	return 0;
}
