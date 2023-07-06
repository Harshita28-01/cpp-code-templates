// O(log n) approach using Sparse Trees and Binary Lifting:- O(n logn + q logn): for creation and q are queries

#include <bits/stdc++.h>
  using namespace std;
  
  int parent[100001][18];
  int levelOf[100001];
  int tin[100001],tout[100001];
  void fillSparse(int node,int prev,int level,int &t,vector<int> adj[]){
    parent[node][0]=prev;
    levelOf[node]=level;
    tin[node]=(++t);
    for(int next:adj[node]){
      if(next==prev){
        continue;
      }
      fillSparse(next,node,level+1,t,adj);
    }
    tout[node]=t;
  }
  
  bool isAncestor(int u,int v){
    // v is deeper than u
    return tin[u]<=tin[v] && tout[u]>=tout[v];
  }
  
  int getLCA(int u,int v){
    if(isAncestor(u,v)){
      return u;
    }
    if(isAncestor(v,u)){
      return v;
    }
    for(int i=17;i>=0;i--){
      if(parent[u][i]!=-1 && !isAncestor(parent[u][i],v)){
        u=parent[u][i];
      }
    }
    return parent[u][0];
  }
  
  int getDist(int u,int v){
    int lca=getLCA(u,v);
    return levelOf[v]+levelOf[u]-2*levelOf[lca];
  }

  int main() {
    int n;
    cin>>n;
    vector<int> adj[n];
    int a,b;
    for(int i=0;i<n-1;i++){
      cin>>a>>b;
        //Assuming 1-based indexing
      a--,b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    memset(parent,-1,sizeof(parent));
    memset(levelOf,-1,sizeof(levelOf));
    int t=0;
    fillSparse(0,-1,0,t,adj);
    for(int j=1;j<=17;j++){
      for(int i=0;i<n;i++){
        if(parent[i][j-1]!=-1){
          parent[i][j]=parent[parent[i][j-1]][j-1];
        }else{
          parent[i][j]=-1;
        }
      }
    }
    return 0;
  }


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
