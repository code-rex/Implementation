/*
There is a row of seats. Assume that it contains N seats adjacent to each other. 
There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat 
between them in such a way that the total number of hops or jumps to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

Example

Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -

              . . . . x . . x x . . . x . .

Now to make them sit together one of approaches is -
                  . . . . . . x x x x . . . . .

Following are the steps to achieve this -
1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 
In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 )%MOD 
    = 25 which is very costly and not an optimized way to do this movement
    */
    
/*
Intuituion: Sol :slight_smile:

Make an array and store (index of 1st x - 0) , (index of 2nd x- 1) , … (index of kth x -(k-1)).
Take the median of this array and then take sum of abs(median - i th element of array) where i starts from 0 to the size of array.

Explanation :wink:

Assume that 1st x goes to index 0, 2nd x to index 1 and so on kth x to index k-1. So the total moves reqd will be

(index of 1st x - 0) + (index of 2nd x- 1) + … (index of kth x -(k-1))

Now assume if we have to start sequence from jth position so moves reqd will be

abs (index of 1st x - j) + abs (index of 2nd x- 1 - j) … + abs(index of kth x -(k-1)-j)

Since we need to find optimal j in this case it reduces to finding the minimum sum of points 
distance from a point . Which is minimum for the median of the array.
*/

int Solution::seats(string A) {
    int n=A.length();
    int MOD = 10000003;
    vector<int>a;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='x'){
            a.push_back(i-count);
            count++;
        }
    }
    int median;
    n=a.size();
    if(n==0)
        return 0;
    if(a.size()%2==0)
        median = (a[n/2]+a[(n-1)/2])/2;
    else
        median = a[n/2];
    long long int ans=0;
    for(int i=0;i<a.size();i++)
        ans+=abs(median-a[i]);
    return ans%MOD;
}
