//Digitwise sorting(LSD to MSD). takes linear time for sorting range 1 - n^2 where counting sort will take O(n^2) time
//Counting sort is a linear time sorting algorithm that sort in O(n+k) time when elements are in range from 1 to k.
//Radix sort uses counting sort as a subroutine to sort .

//Time complexity: Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers, 
//for example, for decimal system, b is 10.
/*
1)What is the value of d? If k is the maximum possible value, then d would be O(logb(k)). So overall time complexity is O((n+b) * logb(k)).
   Which looks more than the time complexity of comparison based sorting algorithms for a large k.
2)Let us first limit k. Let k <= n^c where c is a constant. In that case, the complexity becomes O(nLogb(n)). But it still doesn’t beat 
  comparison based sorting algorithms.
3)What if we make value of b larger?. What should be the value of b to make the time complexity linear? If we set b as n, we get the 
   time complexity as O(n). In other words, we can sort an array of integers with range from 1 to nc if the numbers are represented in 
   base n (or every digit takes log2(n) bits).
*/

/*
Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort?
If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers. 
The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more effectively. 
Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.
*/

void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(int arr[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
