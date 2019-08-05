/*
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is 
much greater than number of nodes on a level.
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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    //associating level 
    pair<TreeNode*,int>p;
    queue<pair<TreeNode*,int>>s;
    s.push({A,0});
    
    map<int,vector<int>>ans;
    
    while(!s.empty())
    {
        pair<TreeNode*,int> top=s.front();
        s.pop();
        int level=top.second;
        TreeNode* value=top.first;
        
        //cout<<value->val<<" ";
        ans[level].push_back(value->val);
        
        if(value->left!=NULL)
            s.push({value->left,level+1});
        if(value->right!=NULL)
            s.push({value->right,level+1});
    }
    vector<vector<int>>res;
    for(auto x : ans)
        res.push_back(x.second);
    return res;
}
