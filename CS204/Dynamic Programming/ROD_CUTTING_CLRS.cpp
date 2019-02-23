//ROD Cutting
//Time-complexity O(n^2) -->average bound
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//revenue araay and s[j] to hold the optimal size 
int r[100],s[100];
void bottom_up(int n,int p[])
{
	r[0]=0;
	//calculating revenue uptil n (optimal substructure)
	for(int j=1;j<=n;j++)
	{
		int q=-1000000;
		//cuts for each revenue 
		for(int i=1;i<=j;i++)
		{
			if(p[i]+r[j-i]>q)
			{
				q=p[i]+r[j-i];
				s[j]=i;  //optimal size of each piece
			}
		}
		//storing the jth revenue which help in calculating nth revenu
		r[j]=q;
	}
}
void extended_bottom_up(int n,int p[])
{
	cout<<"Pieces :";
	while(n)
	{
		cout<<s[n]<<" ";
		n=n-s[n];
	}
}
int main()
{
	int n;
	cin>>n;
	int p[n+1];
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cout<<"Length of rod"<<endl;
	int l;
	cin>>l;
	bottom_up(l,p);
	cout<<"Revenue :"<<r[l]<<endl;
    extended_bottom_up(l,p);
}
