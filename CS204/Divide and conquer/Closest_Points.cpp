#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class point
{
	public:
	int x,y;
};
bool cmpx(point a,point b)
{
	return a.x<b.x;
}
bool cmpy(point a,point b)
{
	return a.y<b.y;
}
float distance(point a,point b)
{
   return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
float bruteforce(point p[],int n)
{
	float min=FLT_MAX;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(distance(p[i],p[j])<min)
				min=distance(p[i],p[j]);
	return min;
}
float stripclosest(point strip[],float d,int n)
{
	float min = d;
	sort(strip,strip+n,cmpy);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n && strip[j].y-strip[i].y<min;j++)
			if(distance(strip[j],strip[i])<min)
				min=distance(strip[j],strip[i]);
	return min;
}
float closest(point p[],int n)
{
	if(n<=3)
    	return bruteforce(p,n);
    int mid=n/2;
    float dl=closest(p,mid);
    float dr=closest(p+mid,n-mid);
    float d=min(dl,dr);
    point midpoint = p[mid];

    //calculating the strip array(refer to geeksforgeeks)
    int j=0;
    point strip[n];
    for(int i=0;i<n;i++)
    	if(abs(midpoint.x-p[i].x)<d)
    		strip[j]=p[i],j++;
    return min(d,stripclosest(strip,d,j));
}
int main()
{
	int n;
	cin>>n;
	point p[n+1];
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
    sort(p,p+n,cmpx);
    cout<<closest(p,n);
	return 0;
}
