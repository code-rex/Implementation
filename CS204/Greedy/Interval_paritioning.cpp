#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MinIndexedPQ
{
	//miniumum finish time along all classroom for given interval
	//minimum is maintained by finish time
	//returning the classroom index whose finish time is latest
	int nmax,n,*keys,*heap,*index;
	//keys contain finish time
	//index contains class-room
	//heap contain lecture
	void swapd(int i,int j)
	{
		swap(heap[i],heap[j]);
		index[heap[i]]=i;
		index[heap[j]]=j;
	}
	void bubbleup(int k)
	{
		while(k>1&&keys[heap[k/2]]>keys[heap[k]])
			swapd(k,k/2),k=k/2;
	}
	void bubbledown(int k)
	{
		while(2*k<=n)
		{
			int j=2*k;
			if(j<n && keys[heap[j]]>keys[heap[j+1]])
				j++;
			if(keys[heap[k]]<=keys[heap[j]])
				break;
			swapd(k,j);
			k=j;
		}
	}
	public:
		MinIndexedPQ(int nmax)
		{
			this->nmax=nmax;
			n=0;
			keys=new int[nmax+1];
			index=new int[nmax+1];
			heap=new int[nmax+1];
			for(int i=0;i<=nmax;i++)
				index[i]=-1;
		}
		void insert(int i,int key)
		{
			n++;
			//ith interval in nth class-room(lecture->class)
			index[i]=n;
			//ith lecture in nth class(class->lecture)
			heap[n]=i;
			//finish time of ith class-room
			keys[i]=key;
			bubbleup(n);
		}
		int minindex()
		{
			return heap[1];
		}
		void increasekey(int i,int key)
		{
			keys[i]=key;
			bubbledown(index[i]);
		}
		int keyof(int i)
		{
			return keys[i];
		}

};
class interval
{
	public:
		int start,end;
};
bool cmp(interval a,interval b)
{
	return a.start<b.start;
}
int main()
{
	cout<<"Enter the no. of interval"<<endl;
	int n;
	cin>>n;
	interval intervals[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the start and end time of interval(lecture): "<<i+1<<endl;
		cin>>intervals[i].start>>intervals[i].end;
	}
	//Sorting by their starting time
	sort(intervals,intervals+n,cmp);
	int schedule[n];
	int d=0;
	schedule[0]=0;
	MinIndexedPQ pq(n);
	pq.insert(0,intervals[0].end);
	for(int i=1;i<n;i++)
	{
		int j=pq.minindex();
		if(intervals[i].start>=pq.keyof(j))
		{
			schedule[i]=j;
			pq.increasekey(j,intervals[i].end);
		}
		else
		{
			d++;
			schedule[i]=d;
			pq.insert(d,intervals[i].end);
		}

	}
	cout<<"Min No. of classroom Needed"<<d+1<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<intervals[i].start<<"-"<<intervals[i].end<<" "<<"classroom: "<<schedule[i]+1<<endl;
	}
	return 0;
}
