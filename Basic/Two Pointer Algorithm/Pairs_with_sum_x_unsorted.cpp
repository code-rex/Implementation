/*
Hashing Approach 
Time Complexity O(N)
Approach :
1) Initialize an empty hash table s.
2) Do following for each element A[i] in A[]
   (a)    If s[x - A[i]] is set then print the pair (A[i], x - A[i])
   (b)    Insert A[i] into s
*/

vector<int> printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) 
    { 
        int temp = sum - arr[i]; 
  
        if (temp >= 0 && s.find(temp) != s.end()) 
            return {arr[i],temp}; 
  
        s.insert(arr[i]); 
    } 
} 
