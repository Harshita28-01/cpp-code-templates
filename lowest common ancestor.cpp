// This code assumes that both the nodes are definitely present in the tree!!!

TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode *leftSubtreeRes=getLCA(root->left,p,q),
        *rightSubtreeRes=getLCA(root->right,p,q);
        if(leftSubtreeRes!=NULL && rightSubtreeRes!=NULL){
            return root;
        }
        if(leftSubtreeRes!=NULL){
            return leftSubtreeRes;
        }
        if(rightSubtreeRes!=NULL){
            return rightSubtreeRes;
        }
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return getLCA(root,p,q);
    }
