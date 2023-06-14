// without parent mapping, space efficient, my ad-hoc method

  int getNodes(TreeNode* root, TreeNode* target, int k,bool found,vector<int> &res){
        if(root==NULL){
            return -1;
        }
        if(root==target){
            found=true;
        }
        if(found){
            if(k==0){
                res.push_back(root->val);
            }else{
                getNodes(root->left,target,k-1,true,res);
                getNodes(root->right,target,k-1,true,res);
            }
            if(root==target){
                return k-1;
            }
            return -1;
        }
        int l=getNodes(root->left,target,k,found,res);
        int r=getNodes(root->right,target,k,found,res);
        if(l==-1 && r==-1){
            return -1;
        }
        if(l==0 || r==0){
            res.push_back(root->val);
            return -1;
        }
        if(l>0){
            getNodes(root->right,target,l-1,true,res);
        }else if(r>0){
            getNodes(root->left,target,r-1,true,res);
        }
        return max(l,r)-1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        getNodes(root,target,k,false,res);
        return res;
    }

// using unordered_map for parent mapping, simple, intuitive but takes more space

void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        if(root==NULL){
            return;
        }
        if(root->left){
            parent[root->left]=root;
            getParents(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            getParents(root->right,parent);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        vector<int> res;
        getParents(root,parent);
        for(int i=0;i<k && q.size();i++){
            int nq=q.size();
            for(int j=0;j<nq;j++){
                TreeNode* cur=q.front();
                q.pop();
                if(parent.count(cur) && !vis.count(parent[cur])){
                    q.push(parent[cur]);
                    vis.insert(parent[cur]);
                }
                if(cur->left && !vis.count(cur->left)){
                    q.push(cur->left);
                    vis.insert(cur->left);
                }
                if(cur->right && !vis.count(cur->right)){
                    q.push(cur->right);
                    vis.insert(cur->right);
                }
            }
        }
        while(q.size()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
