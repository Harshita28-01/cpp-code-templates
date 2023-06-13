vector<int> getLeftBoundary(Node *root){
        vector<int> res;
        while(root){
            res.push_back(root->data);
            if(root->left!=NULL){
                root=root->left;
            }else{
                root=root->right;
            }
        }
        // will be counted in leaves
        if(res.size()){
            res.pop_back();
        }
        return res;
    }
    void getLeaves(Node *root,vector<int>&leaves){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            leaves.push_back(root->data);
            return;
        }
        getLeaves(root->left,leaves);
        getLeaves(root->right,leaves);
    }
    vector<int> getRightBoundary(Node *root){
        vector<int> res;
        while(root){
            res.push_back(root->data);
            if(root->right){
                root=root->right;
            }else{
                root=root->left;
            }
        }
        // will be counted in leaves
        if(res.size()){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }
public:
    vector <int> boundary(Node *root)
    {
        if(root==NULL){
            return {};
        }
        vector<int> res={root->data};
        // if root node is the only leaf node
        if(root->left==NULL && root->right==NULL){
            return res;
        }
        vector<int> leftBoundary=getLeftBoundary(root->left),
        leaves,
        rightBoundary=getRightBoundary(root->right);
        getLeaves(root,leaves);
        // add all the boundaries together
        res.insert(res.end(),leftBoundary.begin(),leftBoundary.end());
        res.insert(res.end(),leaves.begin(),leaves.end());
        res.insert(res.end(),rightBoundary.begin(),rightBoundary.end());
        return res;
    }
