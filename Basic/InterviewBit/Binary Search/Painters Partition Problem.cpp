/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given
how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints 
that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
     return minimum time to paint all boards % 10000003
Example

Input : 
  K : 2
  T : 5
  L : [1, 10]
Output : 50
*/

int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    if(n==1 && A==1)
        return (B*C[0])%10000003;
        
    long long lo=*max_element(C.begin(),C.end());
    long long hi=accumulate(C.begin(),C.end(),0);
    
    //Doing partition
    long long max_load=INT_MAX;
    while(lo<hi)
    {
        long long x=(lo+hi)/2;
        long long required=1,current_load=0;
        for(int i=0;i<n;i++){
            current_load+=C[i];
                if(current_load>x)
                {
                    required++;
                    current_load=C[i];
                }
        }
        if(required<=A)
            hi=x;
        else
            lo=x+1;
    }
    //calculating cost
    long long result=(lo*B)%10000003;
    return (int)result;
}
