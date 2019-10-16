class Solution {
public:
    // DFS magic : initialize stack and do the following 
    // pop top, retrieve neighbours for top, push unvisited neighbours to stack | repeat while stack not empty 
    // because this is a tree no need to keep track of visited as no cycles possible. 
    
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        
        s.push(root);
        
        while(!s.empty()){
            TreeNode* current = s.top(); s.pop();  // pop top 
            
            if(current != NULL){
                // push unvisited neighbours to stack | order matters here, if you reverse it 
                // it would still be a DFS but a symmetric one to preorder out of the 6 possible combinations.  
                s.push(current->right);
                s.push(current->left);
                
                result.push_back(current->val);
            }
        }
        
        return result;
    }
};
