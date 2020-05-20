/*
Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.



Input Format:

The only argument given is string A.
Output Format:

Return the length of the longest valid (well-formed) parentheses substring.
Constraints:

1 <= length(A) <= 750000
For Example

Input 1:
    A = "(()"
Output 1:
    2
    Explanation 1:
        The longest valid parentheses substring is "()", which has length = 2.

Input 2:
    A = ")()())"
Output 2:
    4
    Explanation 2:
        The longest valid parentheses substring is "()()", which has length = 4.
*/

int Solution::longestValidParentheses(string A) {
    
    int n=A.length();
    stack<int> st;
    st.push(-1);

    int mx=0;
    for(int i=0; i<A.length(); i++){
        if(A[i]=='('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()==false){
                mx = max(mx, i-st.top());
            }
            else{
                st.push(i);
            }
        }
    }

    return mx;    
}
