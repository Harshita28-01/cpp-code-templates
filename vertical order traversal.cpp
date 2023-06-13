// using multiset

  void getNodeData(TreeNode* root,map<int,map<int,multiset<int>>> &nodedata,int col,int row){
        if(root==NULL){
            return;
        }
        nodedata[col][row].insert(root->val);
        getNodeData(root->left,nodedata,col-1,row+1);
        getNodeData(root->right,nodedata,col+1,row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        // [col][row]
        map<int,map<int,multiset<int>>> nodedata;
        getNodeData(root,nodedata,0,0);
        for(auto &colData:nodedata){
            vector<int> col;
            for(auto rowData:colData.second){
                multiset<int> &node=rowData.second;
                col.insert(col.end(),node.begin(),node.end());
            }
            res.push_back(col);
        }
        return res;
    }

// using vector<int> and then sorting

void getNodeData(TreeNode* root,map<int,map<int,vector<int>>> &nodedata,int col,int row){
        if(root==NULL){
            return;
        }
        nodedata[col][row].push_back(root->val);
        getNodeData(root->left,nodedata,col-1,row+1);
        getNodeData(root->right,nodedata,col+1,row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        // [col][row]
        map<int,map<int,vector<int>>> nodedata;
        getNodeData(root,nodedata,0,0);
        for(auto &colData:nodedata){
            vector<int> col;
            for(auto rowData:colData.second){
                vector<int> &node=rowData.second;
                sort(node.begin(),node.end());
                col.insert(col.end(),node.begin(),node.end());
            }
            res.push_back(col);
        }
        return res;
    }

// a sort of hashing algo i made during my early days

  vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<int>> um;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        int minCol=0,maxCol=0,maxRow=0;
        while(!q.empty()){
            int i=q.front().second.first,j=q.front().second.second;
            TreeNode* cur=q.front().first;
            q.pop();
            if(um.count(i*1000+j)){
                um[i*1000+j].push_back(cur->val);
            }else{
                vector<int> temp;
                temp.push_back(cur->val);
                um[i*1000+j]=temp;
            }
            maxRow=max(maxRow,i);
            minCol=min(minCol,j);
            maxCol=max(maxCol,j);
            if(cur->left!=NULL)q.push({cur->left,{i+1,j-1}});
            if(cur->right!=NULL)q.push({cur->right,{i+1,j+1}});
        }
        vector<vector<int>> res;
        for(int j=minCol;j<=maxCol;j++){
            vector<int> temp;
            for(int i=0;i<=maxRow;i++){
                int hash=1000*i+j;
                if(!um.count(hash))continue;
                sort(um[hash].begin(),um[hash].end());
                temp.insert(temp.end(),um[hash].begin(),um[hash].end());
            }
            if(temp.size()!=0)res.push_back(temp);
        }
        return res;
    }
