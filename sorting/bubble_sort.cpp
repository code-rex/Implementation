//bubble sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int flag=0;
	int runner=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]),flag=1;
			}
			runner++;
		}
		if(flag==0)
			break;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<runner<<endl;
	return 0;
}
