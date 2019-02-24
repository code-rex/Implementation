//Fractional Knapsack problem
//Time complexity -->O(nlogn)
//Greedy Approach sorting by v/w 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
		int weight,value;
};
bool cmp(node a,node b)
{
	return double(a.value/a.weight)>double(b.value/b.weight);
}
double Knapsack(node wv[],int n,int capacity)
{
	double cost=0.0;
	for(int i=0;i<n;i++)
	{
		if(wv[i].weight<=capacity)
		{
			cost+=wv[i].value;
		    capacity = capacity-wv[i].weight;
		}
		else
		{
				cost+=wv[i].value*((double)capacity/wv[i].weight);
				break;
		}

	}
	return cost;
}
int main()
{
	int n;
	cin>>n;
	node wv[n];
	for(int i=0;i<n;i++)
		cin>>wv[i].weight>>wv[i].value;
	int capacity;
	cin>>capacity;
	sort(wv,wv+n,cmp);
	double max_value = Knapsack(wv,n,capacity);
	cout<<max_value<<endl;
	return 0;
}
