/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4
*/

/*
Approach:
if any number appeared thrice then in its binary representation 0s,3s also occured thrice
hence doing sum of binary-digit of all bits mod3 will ensure binary outcome(2 will not occur)
hence answer will be binary number generated after mod of sum at every position i of all
number.
1.Make an array of size 32 and store the sum of bit at position i .then do mod 3 reultant
  is answer.
2.Do like below without storing.
*/
int Solution::singleNumber(const vector<int> &A) {
    int result=0;
    int sum,x;
    int n=A.size();
    
    for(int i=0;i<32;i++)//for 32 bit integer
    {
        sum = 0;//sum of ith set bit of all element  
        x = (1 << i); //x=pow(2,i) 001,010,100...
        for (int j=0; j< n; j++ ) 
        { //And will checker whether ith position of A[i] is set or not
          if (A[j] & x) //if 1 then add
            sum++;
        }
      if (sum % 3) 
        result |= x; //setting that bit in ans whose remainder is 1
    }
    return result;
}

//Elegant solution
int Solution::singleNumber(const vector<int> &A) {
    int first = 0;
    int second = 0;
    for(auto n:A){
        first = (first ^ n) & ~second;
        second = (second ^ n) & ~first;
    }
    return first;
}
