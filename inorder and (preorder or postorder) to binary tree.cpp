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
