/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

*/
int MaxAreaOfHist(vector<int> &arr){
    stack<int> S;
    int n = arr.size(), i = 0, maxarea = 0;
    while(i < n){
        if(S.empty() || arr[i] >= arr[S.top()]){
            S.push(i); i++;
        }
        else{
            int tp = S.top();
            S.pop();
            if(S.empty())
                maxarea = max(maxarea, arr[tp]*i);
            else
                maxarea = max(maxarea, arr[tp]*(i-1-S.top()));
        }
    }
    while(!S.empty()){
        int tp = S.top();
        S.pop();
        if(S.empty())
            maxarea = max(maxarea, arr[tp]*i);
        else
            maxarea = max(maxarea, arr[tp]*(i-1-S.top()));
    }
    return maxarea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int maxarea = MaxAreaOfHist(A[0]);
    for(int i=1; i<A.size(); i++){
        for(int j=0; j<A[i].size(); j++){
            if(A[i][j] != 0)
                A[i][j] += A[i-1][j];
        }
        maxarea = max(maxarea, MaxAreaOfHist(A[i]));
    }
    return maxarea;
}
