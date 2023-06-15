// RECURSIVE TOO EASY

// ITERATIVE SOLUTIONS

// 1. Preorder- 1 stack

  vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root){
            st.push(root);
        }
        vector<int> preorder;
        while(st.size()){
            TreeNode* cur=st.top();
            st.pop();
            preorder.push_back(cur->val);
            // first push right
            if(cur->right){
                st.push(cur->right);
            }
            // then push left
            if(cur->left){
                st.push(cur->left);
            }
        }
        return preorder;
    }

// 2. Inorder- 1 stack and 1 TreeNode* variable

  vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int> inorder;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }else{
                if(st.size()==0){
                    break;
                }
                TreeNode* cur=st.top();
                st.pop();
                inorder.push_back(cur->val);
                node=cur->right;
            }
        }
        return inorder;
    }

// 3.1 Postorder- 1 stack (but reverse the array)

  vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root){
            st.push(root);
        }
        vector<int> postorder;
        while(st.size()){
            TreeNode* cur=st.top();
            st.pop();
            postorder.push_back(cur->val);
            if(cur->left){
                st.push(cur->left);
            }
            if(cur->right){
                st.push(cur->right);
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }

// 3.2 Postorder- 1 stack (without reversing the array)

  vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        vector<int> postorder;
        while(st.size() || node){
            if(node){
                st.push(node);
                node=node->left;
            }else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(st.size() && st.top()->right==temp){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }else{
                    node=temp;
                }
            }
        }
        return postorder;
    }

// MORRIS TRAVERSALS, O(1) Space binary tree traversals

/*
1. if(node->left is NULL), we have to explore right
2. else go to rightest of node->left
    I. If the current node is encountered, then we’re visiting this node a second time
    II. else we’re visiting it for the first time, make its right connection to the current node

*/

// 1. Preorder traversal

  vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode *node=root;
        while(node){
            if(node->left==NULL){
                preorder.push_back(node->val);
                node=node->right;
            }else{
                TreeNode *prev=node->left;
                while(prev->right && prev->right!=node){
                    prev=prev->right;
                }
                if(prev->right){
                    prev->right=NULL;
                    node=node->right;
                }else{
                    prev->right=node;
                    preorder.push_back(node->val);
                    node=node->left;
                }
            }
        }
        return preorder;
    }

// 2. Inorder Traversal

  vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *node=root;
        while(node){
            if(node->left == NULL){
                inorder.push_back(node->val);
                node=node->right;
            }else{
                TreeNode *it=node->left;
                while(it->right && it->right!=node){
                    it=it->right;
                }
                if(it->right){
                    it->right=NULL;
                    inorder.push_back(node->val);
                    node=node->right;
                }else{
                    it->right=node;
                    node=node->left;
                }
            }
        }
        return inorder;
    }

// 3. Postorder traversal

  vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        TreeNode *node=root;
        while(node){
            if(node->right==NULL){
                postorder.push_back(node->val);
                node=node->left;
            }else{
                TreeNode *it=node->right;
                while(it->left && it->left!=node){
                    it=it->left;
                }
                if(it->left){
                    it->left=NULL;
                    node=node->left;
                }else{
                    it->left=node;
                    postorder.push_back(node->val);
                    node=node->right;
                }
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
