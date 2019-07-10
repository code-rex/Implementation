/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

//Approach 1 Backtracking
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
 Don't do &aux because doing this will make change to original array 
 (when call stack happens). 
 aux(changes will not reflect back in original aux array) will make copies(copy of vector)
 when call stack is called hence no need to pop_back as we do in backtracking.
*/
//Think of every call as next run in while loop after total loop execution
void haspath(TreeNode* a,int b,vector<int>&aux,vector<vector<int>>&ans)
{
    if(a==NULL)
        return ;
        
    aux.push_back(a->val);
    if(a->left==NULL && a->right==NULL && b-a->val == 0)
        ans.push_back(aux);
        
    //Considering current element to be in answer check left and right subtree
    haspath(a->left,b-a->val,aux,ans);
    haspath(a->right,b-a->val,aux,ans);
    
    //if no path including this element remove the element from vector(Backtracking)
    aux.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>ans;
    vector<int>aux;
    haspath(A,B,aux,ans);
    return ans;
}

//Approach 2
void haspath(TreeNode* a,int b,vector<int>aux,vector<vector<int>>&ans)
{
    if(a==NULL)
        return ;
    //Condition for leaf node
    if(a->left==NULL && a->right==NULL && b-a->val == 0){
        aux.push_back(a->val);
        ans.push_back(aux);
    }
    
    //Recur to both subtree(exploring all posibilities)
    aux.push_back(a->val);
    haspath(a->left,b-a->val,aux,ans);
    haspath(a->right,b-a->val,aux,ans);
    
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>ans;
    vector<int>aux;
    haspath(A,B,aux,ans);
    return ans;
}
