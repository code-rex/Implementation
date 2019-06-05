//In kadane it is assumend that atleaset one no. is positive.
//if that is not the case (when all are negative) make a temporary variable
//and max of all negative is ans i.e. max_element;
#include<bits/stdc++.h>
using namespace std;
vector<int> maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0;
    int max_element = INT_MIN;
    int record; 
  	for (int i=0; i< size; i++ ) 
    { 
    	if(max_element<a[i])
    	{
    		max_element=a[i];
    		record=i;
    	}
        max_ending_here += a[i];
		if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
  		else if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        }       
    }
    //Handling negative case
    if (max_so_far == INT_MIN){
	  max_so_far = max_element;
	  start = record,end = record;
    }
	
	return {max_so_far,start,end}; 
} 
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int>ans = maxSubArraySum(a,n);
	cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
	}
	return 0;
}
