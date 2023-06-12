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
