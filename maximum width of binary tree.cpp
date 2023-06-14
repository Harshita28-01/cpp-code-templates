  int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int res=0;
        while(q.size()){
            int nq=q.size(),first=q.front().second,mini=-1;
            for(int j=0;j<nq;j++){
                TreeNode *cur=q.front().first;
                int i=q.front().second;
                q.pop();
                res=max(res,i-first+1);
                if(mini==-1 && (cur->left || cur->right)){
                    mini=i;
                }
                if(cur->left){
                    q.push({cur->left,2*(i-mini)});
                }
                if(cur->right){
                    q.push({cur->right,2*(i-mini)+1});
                }
            }
        }
        return res;
    }
