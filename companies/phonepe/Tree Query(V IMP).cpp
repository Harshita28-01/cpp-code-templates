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
    int x,y,a,b,k;
    for(int i=0;i<n-1;i++){
      cin>>a>>b;
      a--,b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int nq;
    cin>>nq;
    vector<vector<int>> queries;
    for(int i=0;i<nq;i++){
      cin>>x>>y>>a>>b>>k;
      x--,y--,a--,b--;
      queries.push_back({x,y,a,b,k});
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
    for(vector<int> &query:queries){
      x=query[0],y=query[1],a=query[2],b=query[3],k=query[4];
      int x1=getDist(a,b);
      if(x1<=k && ((x1&1) == (k&1))){
        cout<<"YES"<<endl;
        continue;
      }
      x1=getDist(a,x)+1+getDist(y,b);
      if(x1<=k && ((x1&1) == (k&1))){
        cout<<"YES"<<endl;
        continue;
      }
      x1=getDist(a,y)+1+getDist(x,b);
      if(x1<=k && ((x1&1) == (k&1))){
        cout<<"YES"<<endl;
        continue;
      }
      cout<<"NO"<<endl;
    }
    return 0;

  }
