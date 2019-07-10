/*
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.

*/

int Solution::maxDepth(TreeNode* root) {
    if(root==NULL)  
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left,right)+1;
}
