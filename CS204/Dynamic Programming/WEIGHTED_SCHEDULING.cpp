#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int table[100];
int binary[100]={0};
class interval
{
	public:
		int start,finish,weight;
};
//Sorting by finish time in ascending order
bool cmp(interval a,interval b)
{
	return a.finish<b.finish;
}
//Binary search for finding immediate previous job 
int binary_search(interval a[],int x)
{
	int lo=0;int hi=x-1;
	while(lo<=hi)
	{
		int mid=(lo+hi)/2;
		if(a[mid].finish<=a[x].start)
		{
			if(a[mid+1].finish<=a[x].start)
				lo = mid+1;
			else
				return mid;
		}
		else
			hi=mid-1;

	}
	return -1;
}
int weighted_scheduling(interval a[],int n)
{
	if(n==1)
		return a[n-1].weight;
	//table[i] stores the profit for jobs till arr[i] (including arr[i]) 
	//including the first job
	table[0]=a[0].weight;
	for(int i=1;i<n;i++)
	{
	    int include=a[i].weight;
	    //finding the immediate previous job whose finish time is less than start time of current job
	    binary[i]=binary_search(a,i);
		if(binary[i]!=-1)
			include+=table[binary[i]];
	//store maximum of including or excluding the current job
		table[i]=max(table[i-1],include);
	}
	return table[n-1];
}
void find_solution(interval a[],int j)
{
	if(j==0)
		cout<<a[j].start<<" "<<a[j].finish<<" "<<a[j].weight<<endl;
	
	else if(a[j].weight+table[binary[j]]>table[j-1])
		{
			cout<<a[j].start<<" "<<a[j].finish<<" "<<a[j].weight<<endl;
			find_solution(a,binary[j]);
		}
	else
		find_solution(a,j-1);

}
int main()
{
	int n;
	cin>>n;
	interval a[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter start time ,finish time and weight"<<endl;
		cin>>a[i].start>>a[i].finish>>a[i].weight;
	}
	sort(a,a+n,cmp);
	cout<<weighted_scheduling(a,n)<<endl;
	find_solution(a,n-1);
	return 0;
}
//4 3 10 20 1 2 50 6 19 100 2 100 200
//6 2 5 6 1 3 5 6 7 4 4 6 5 7 9 2 5 8 11
//5 1 2 10 2 4 9 3 5 7 6 11 8 5 10 5
