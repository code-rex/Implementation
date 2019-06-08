//for negative numbers too
//time complexity : O(n+k) k=range
//Counting sort uses a partial hashing to count the occurrence of the data object in O(1).

//The Counting sort is a stable sort i.e., multiple keys with the same value are placed in 
//the sorted array in the same order that they appear in the input array.

void countSort(vector <int>& arr) 
{ 
    int max = *max_element(arr.begin(), arr.end()); 
    int min = *min_element(arr.begin(), arr.end()); 
    int range = max - min + 1; 
      
    vector<int> count(range), output(arr.size()); 
    for(int i = 0; i < arr.size(); i++) 
        count[arr[i]-min]++; 
          
    for(int i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(int i = arr.size()-1; i >= 0; i--) //1
    {  
         output[ count[arr[i]-min] -1 ] = arr[i];  
              count[arr[i]-min]--;  
    } 
      
    for(int i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 

//if at pos 1 i<-1 to n then then the stability no longer holds.
