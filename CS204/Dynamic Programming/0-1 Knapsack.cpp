#include<bits/stdc++.h>  
using namespace std;
int n,W;
int K[100][100];   
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int wt[], int val[]) 
{ 
   int i, w; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
void find_solution(int wt[],int val[])
{
    //if item is picked the value will change going up
    int w=W;
    while(w>0&&n>0)
    {
      if(K[n][w]!=K[n-1][w])
      {
        cout<<n<<" ";
        w=w-wt[n-1];
        n=n-1;
      }
      else
        n=n-1;
    } 
}
int main() 
{ 
    cout<<"Enter Number of items"<<endl;
    cin>>n;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    {
      cout<<"Enter the value and weight of "<<i+1<<endl;
      cin>>val[i]>>wt[i];
    }
    cout<<"Enter Weight of the Bag"<<endl;
    cin>>W;
    printf("Maximum value : %d", knapSack( wt, val));
    cout<<endl;
    cout<<"Picked Item : ";
    find_solution(wt,val); 
    return 0; 
}
