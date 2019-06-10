/*
Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

O(n) with no extra space

Discuss : dont remove individual element, Push all to right then erase whole(or just resize)
*/

int removeDuplicates(int A[], int n) {
            int count = 0;
            for (int i = 0; i < n; i++) { 
                if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
                else {
                    A[count] = A[i];
                    count++;
                }
            }
            A.resize(count);
            return count;
          }
