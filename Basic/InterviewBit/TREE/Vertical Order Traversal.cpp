/*
Given a binary tree, return a 2-D array with vertical order traversal of it.
Go through the example and image for more details.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.
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
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(!A)
        return {};
        
    unordered_map<int,vector<int>>m;
    vector<vector<int>>ans;
    int mi=INT_MAX,ma=INT_MIN;
    
    queue<pair<int,TreeNode*>>q;
    q.push(make_pair(0,A));
    //Level Order Traversal 
    while(!q.empty())
    {
        int height=q.front().first;
        TreeNode* Node=q.front().second;
        q.pop();
        m[height].push_back(Node->val);
        mi = min(mi,height);
        ma = max(ma,height);
        //Visit left and right of popped node
        if(Node->left)
            q.push(make_pair(height-1,Node->left));
        if(Node->right)
            q.push(make_pair(height+1,Node->right));
    }
    
    for(int i=mi;i<=ma;i++)
        ans.push_back(m[i]);
    
    return ans;
}
