/*
Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space. It is required that the order in which elements repeat 
should be maintained. If there is no repeating element present then print -1.

Space - O(1)
TIME - O(N)
ORDER OF ELEMENT IS MAINTAINED
Range of Given no. 0 to n-1
2 1 3 3 4 5 5 5 -> 3 5
*/

void printDuplicates(int arr[], int n) 
{ 
    int i; 
  
    // Flag variable used to 
    // represent whether repeating 
    // element is found or not. 
    int fl = 0; 
  
    for (i = 0; i < n; i++) { 
  
        // Check if current element is 
        // repeating or not. If it is 
        // repeating then value will 
        // be greater than or equal to n. 
        if (arr[arr[i] % n] >= n) { 
  
            // Check if it is first 
            // repetition or not. If it is 
            // first repetition then value 
            // at index arr[i] is less than 
            // 2*n. Print arr[i] if it is 
            // first repetition. 
            if (arr[arr[i] % n] < 2 * n) { 
                cout << arr[i] % n << " "; 
                fl = 1; 
            } 
        } 
  
        // Add n to index arr[i] to mark 
        // presence of arr[i] or to 
        // mark repetition of arr[i]. 
        arr[arr[i] % n] += n; 
    } 
  
    // If flag variable is not set 
    // then no repeating element is 
    // found. So print -1. 
    if (!fl) 
        cout << "-1"; 
} 
