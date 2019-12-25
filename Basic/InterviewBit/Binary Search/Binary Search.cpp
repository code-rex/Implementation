//O indexing
//Recursive

int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle itself 
        if (arr[mid] == x)  return mid; 
  
        // If element is smaller than mid, then it can only be present 
        // in left subarray 
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x); 
  
        // Else the element can only be present in right subarray 
        return binarySearch(arr, mid+1, r, x); 
   } 
  
   // We reach here when element is not present in array 
   return -1; 
} 

//Iterative
int binarySearch(int arr[], int l, int r, int x) 
{ 
  while (l <= r) 
  { 
    int m = l + (r-l)/2; 
  
    // Check if x is present at mid 
    if (arr[m] == x)  
        return m;   
  
    // If x greater, ignore left half   
    if (arr[m] < x)  
        l = m + 1;  
  
    // If x is smaller, ignore right half  
    else 
         r = m - 1;  
  } 
  
  // if we reach here, then element was not present 
  return -1;  
} 

-------------------Lower and upper bound---------------------------
   #include<iostream>
using namespace std;


int lowerBound(int *a,int n,int key){
    int s =0,e=n-1;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;

        if(a[mid]==key){
            ans = mid;
            e = mid - 1;
        }
        else if(a[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return ans;
}

int upperBound(int *a,int n,int key){
    int s =0,e=n-1;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;

        if(a[mid]==key){
            ans = mid;
            s = mid+1;
        }
        else if(a[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return ans;
}

int main(){
    int a[] = {1,2,2,2,2,2,3,3,3,5,5,5};
    int n = sizeof(a)/sizeof(int);
    cout<<lowerBound(a,n,2)<<endl;
    cout<<upperBound(a,n,2)<<endl;


return 0;
}

//reference - https://codingblocks.com/resources/binary-search-upper-lower-bound/
