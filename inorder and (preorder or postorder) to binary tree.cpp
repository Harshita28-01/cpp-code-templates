//preorder and postorder and never give an unique binary tree

// inorder and preorder

  TreeNode* getSubTree(int preL,int preR,int inL,int inR,vector<int>& preorder, vector<int>& inorder){
        if(preL>preR){
            return NULL;
        }
        // first node of our preorder is our root
        TreeNode *root=new TreeNode(preorder[preL]);
        int leftSize=0;
        while(inL+leftSize<=inR && root->val!=inorder[inL+leftSize]){
            leftSize++;
        }
        root->left=getSubTree(preL+1,preL+leftSize,inL,inL+leftSize-1,preorder,inorder);
        root->right=getSubTree(preL+1+leftSize,preR,inL+leftSize+1,inR,preorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return getSubTree(0,n-1,0,n-1,preorder,inorder);
    }

// inorder and postorder

  TreeNode* getSubTree(int inL,int inR,int postL,int postR,vector<int>& inorder, vector<int>& postorder){
        if(inL>inR){
            return NULL;
        }
        // last node of postorder is our root
        TreeNode *root=new TreeNode(postorder[postR]);
        int leftSize=0;
        while(inL+leftSize<=inR && root->val!=inorder[inL+leftSize]){
            leftSize++;
        }
        root->left=getSubTree(inL,inL+leftSize-1,postL,postL+leftSize-1,inorder,postorder);
        root->right=getSubTree(inL+leftSize+1,inR,postL+leftSize,postR-1,inorder,postorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return getSubTree(0,n-1,0,n-1,inorder,postorder);
    }

// OPTIMISATION- use hashmap for inorder root search

// inorder and preorder
  TreeNode* getSubTree(int preL,int preR,int inL,int inR,
                         vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &inorderIndexes){
        if(preL>preR){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[preL]);
        int rootPos=inorderIndexes[root->val];
        int leftSize=rootPos-inL;
        root->left=getSubTree(preL+1,preL+leftSize,inL,rootPos-1,preorder,inorder,inorderIndexes);
        root->right=getSubTree(preL+1+leftSize,preR,rootPos+1,inR,preorder,inorder,inorderIndexes);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> inorderIndexes;
        for(int i=0;i<n;i++){
            inorderIndexes[inorder[i]]=i;
        }
        return getSubTree(0,n-1,0,n-1,preorder,inorder,inorderIndexes);
    }

// inorder and postorder

  TreeNode* getSubTree(int inL,int inR,int postL,int postR,vector<int>& inorder, vector<int>& postorder,
                         unordered_map<int,int> &inorderIndexes){
        if(inL>inR){
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[postR]);
        int rootPos=inorderIndexes[root->val];
        int leftSize=rootPos-inL;
        root->left=getSubTree(inL,rootPos-1,postL,postL+leftSize-1,inorder,postorder,inorderIndexes);
        root->right=getSubTree(rootPos+1,inR,postL+leftSize,postR-1,inorder,postorder,inorderIndexes);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> inorderIndexes;
        for(int i=0;i<n;i++){
            inorderIndexes[inorder[i]]=i;
        }
        return getSubTree(0,n-1,0,n-1,inorder,postorder,inorderIndexes);
    }

