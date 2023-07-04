#include <bits/stdc++.h>
  using namespace std;
  
  class DSU{
    public:
    vector<int> par,sz;
    DSU(int n):par(n),sz(n){
      iota(par.begin(),par.end(),0);
    }
    int getPar(int u){
      if(par[u]==u){
        return u;
      }
      return par[u]=getPar(par[u]);
    }
    bool join(int u,int v){
      u=getPar(u);
      v=getPar(v);
      if(u==v){
        return false;
      }
      if(sz[u]<sz[v]){
        sz[v]+=sz[u];
        par[u]=v;
      }else{
        sz[u]+=sz[v];
        par[v]=u;
      }
      return true;
    }
  };
  
  
  void addToGraph(int node,vector<int> adj[],vector<bool> &isActive,
  int n,DSU &dsu, vector<int> &res,int &components){
    isActive[node]=true;
    components++;
    for(int next:adj[node]){
      if(isActive[next] && dsu.join(node,next)){
        components--;
      }
    }
    res.push_back(components);
  }
  
  
  vector<int> getAllComponents(vector<int> adj[],int n){
    vector<bool> isActive(n);
    vector<int> res({0});
    int components=0;
    DSU dsu(n);
    for(int i=n-1;i>=1;i--){
      addToGraph(i,adj,isActive,n,dsu,res,components);
    }
    reverse(res.begin(),res.end());
    return res;
  }

  int main() {

    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    int u,v;
    for(int i=0;i<m;i++){
      cin>>u>>v;
      u--,v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> res=getAllComponents(adj,n);
    for(int r:res){
      cout<<r<<endl;
    }
    return 0;

  }
