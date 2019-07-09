/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*>s;
    vector<int>ans;
    TreeNode* curr=A;
    s.push(A);
    
    while(curr->left || curr->right || s.size())
    {
        curr=s.top();
        s.pop();
        ans.push_back(curr->val);
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
    return ans;
}
