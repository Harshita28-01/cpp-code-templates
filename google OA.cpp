// Special Paths

  #include <bits/stdc++.h>
  using namespace std;

  class DSU{
    public:
    vector<int> parent,sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int getParent(int cur){
        if(cur==parent[cur]){
            return cur;
        }
        return parent[cur]=getParent(parent[cur]);
    }
    void setUnion(int u,int v){
        u=getParent(u);
        v=getParent(v);
        if(u==v){
            return;
        }
        if(sz[u]<sz[v]){
            parent[u]=v;
            sz[v]+=sz[u];
        }else{
            parent[v]=u;
            sz[u]+=sz[v];
        }
    }
    bool isUnion(int u,int v){
        return getParent(u)==getParent(v);
    }
};

  int main() {

    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int> v(n);
      map<int,vector<int>> m;
      for(int i=0;i<n;i++){
        cin>>v[i];
        m[v[i]].push_back(i);
      }
      vector<vector<int>> adj(n);
      int a,b;
      for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
      DSU dsu(n);
      vector<bool> isActive(n);
      long long res=0;
      for(auto it=m.begin();it!=m.end();it++){
        vector<int> &idx=it->second;
        for(int cur:idx){
          isActive[cur]=true;
          for(int next:adj[cur]){
            if(isActive[next]){
              dsu.setUnion(cur,next);
            }
          }
        }
        unordered_map<int,int> um;
        for(int cur:idx){
          um[dsu.getParent(cur)]++;
        }
        for(auto it=um.begin();it!=um.end();it++){
          int nn=it->second;
          res+=(long long)nn*(nn-1)/2;
        }
      }
      cout<<res<<endl;
    }
    return 0;

  }
