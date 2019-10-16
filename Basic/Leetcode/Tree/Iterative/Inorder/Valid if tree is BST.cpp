//Sorted Inorder Traversal

bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        stack<TreeNode*> s;
        TreeNode* prev = NULL;
        
        while(root != NULL || !s.empty()){
            while(root != NULL){
                s.push(root);
                root = root->left;
            }    
            
            root = s.top(); s.pop();
            if(prev != NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        
        return true;
    }
