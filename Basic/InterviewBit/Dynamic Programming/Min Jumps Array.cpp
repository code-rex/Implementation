/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example :
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

If it is not possible to reach the end index, return -1.
*/
int jump(int A[], int n) {
            if(n <= 1){
                return 0;
            }
            int maxReachPos = A[0];
            int curMaxReachPos = A[0];
            int curStep = 1;
            for(int i = 1; i <= maxReachPos; i++){
                if(i == n - 1){
                    return curStep;
                }
                curMaxReachPos = max(curMaxReachPos, i + A[i]);
                if(i == maxReachPos){
                    if (curMaxReachPos <= i) return -1;
                    maxReachPos = curMaxReachPos;
                    curStep++;
                }
            }
            return -1;
        }
